//========================================================
//            1. 라이브러리 및 핀 설정
//========================================================
#include <U8g2lib.h> // OLED 디스플레이 라이브러리
#include <SPI.h>     // SPI 통신 라이브러리 (OLED에 필요할 수 있음)
#include <Wire.h>    // I2C 통신 라이브러리 (OLED에 필요)

// OLED 객체 생성: SH1106 칩셋, 128x64 해상도, 하드웨어 I2C 통신
// 리셋 핀이 연결되지 않았다면 U8X8_PIN_NONE 사용 (기본 설정)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// 핀 정의
const int BATTERY_PIN = A0; // 배터리 전압을 측정할 아날로그 핀
const int BUZZER_PIN = 4;   // 부저가 연결된 디지털 핀 (D4)

// 전압 분배기(potential divider) 저항값 설정
const float R1 = 100000.0; // R1 = 100kΩ
const float R2 = 47000.0;  // R2 = 47kΩ

// 전압 분배기 이득(gain) 계산: POT_DIV = R2 / (R1 + R2)
const float POT_DIV = R2 / (R1 + R2);

// 아두이노의 아날로그 기준 전압 설정 (일반적으로 5V를 사용)
const float ANALOG_REFERENCE_VOLTAGE = 5.0;

// 배터리 잔량 계산을 위한 전압 기준 설정 (배터리 종류에 따라 조절 필요)
const float MAX_VOLTAGE = 12.0; // 100% 잔량에 해당하는 전압 (완충)
const float MIN_VOLTAGE = 10.0; // 0% 잔량에 해당하는 전압 (방전)

// 부저 경고를 위한 잔량 기준 설정
const float LOW_BATTERY_THRESHOLD = 5.0; // 5% 미만일 때 경고

// 소프트웨어 보정 계수 (실제 완충 전압 / 측정된 전압)
const float CALIBRATION_FACTOR = 11.9 / 12.8;

//========================================================
//            2. OLED 관련 함수들 정의
//========================================================
// OLED에 배터리 잔량 막대 그래프를 그리는 함수
void displayLevel(int batlevel, float voltage) {
  u8g2.firstPage(); // OLED 화면 버퍼 초기화
  do {
    u8g2.setDrawColor(1); // 그리기 색상 설정 (1은 켜짐, 0은 꺼짐)
    drawSun();            // 해 모양 아이콘 그리기 (OLED 코드 원본에 포함)

    // 10% 단위로 막대 표시 (잔량에 따라 직관적으로 증가)
    if (batlevel >= 10) drawBatt10();
    if (batlevel >= 20) drawBatt20();
    if (batlevel >= 30) drawBatt30();
    if (batlevel >= 40) drawBatt40();
    if (batlevel >= 50) drawBatt50();
    if (batlevel >= 60) drawBatt60();
    if (batlevel >= 70) drawBatt70();
    if (batlevel >= 80) drawBatt80();
    if (batlevel >= 90) drawBatt90();
    if (batlevel >= 100) drawBatt100();

    // 1. 실제 전압 값 표시 (작은 폰트)
    u8g2.setFont(u8g2_font_5x8_tr); // 퍼센트보다 작은 폰트 설정
    char volt_buf[10];
    
    // dtostrf(소수점 변수, 최소 너비, 소수점 이하 자릿수, 저장할 문자열 버퍼);
    dtostrf(voltage, 4, 2, volt_buf); // voltage 값을 소수점 2자리 문자열로 변환
    strcat(volt_buf, "V");            // 변환된 문자열 뒤에 "V"를 붙임
    
    u8g2.drawStr(42, 62, volt_buf);   // 화면에 전압 값 표시

    // 2. 퍼센트 값 표시 (기존과 동일)
    u8g2.setFont(u8g2_font_ncenB10_tr);
    char buf[10];
    sprintf(buf, "%d %%", batlevel);
    u8g2.drawStr(80, 62, buf);

  } while ( u8g2.nextPage() ); // 다음 페이지로 넘어가면서 화면 업데이트
}

// 각 배터리 잔량 막대를 그리는 함수들 (좌표 및 크기는 원본 코드 유지)
void drawBatt10() { u8g2.drawBox(108,0,16,40); } // 가장 오른쪽 두꺼운 막대
void drawBatt20() { u8g2.drawBox(96,0,7,40); }
void drawBatt30() { u8g2.drawBox(84,0,7,40); }
void drawBatt40() { u8g2.drawBox(72,0,7,40); }
void drawBatt50() { u8g2.drawBox(60,0,7,40); }
void drawBatt60() { u8g2.drawBox(48,0,7,40); }
void drawBatt70() { u8g2.drawBox(36,0,7,40); }
void drawBatt80() { u8g2.drawBox(24,0,7,40); }
void drawBatt90() { u8g2.drawBox(12,0,7,40); }
void drawBatt100() { u8g2.drawBox(0,0,7,40); } // 가장 왼쪽 얇은 막대

// 해 모양 아이콘을 그리는 함수 (OLED 코드 원본에 포함)
void drawSun() {
  u8g2.drawDisc(20, 55, 3);
  u8g2.drawLine(20,50,20,46);
  u8g2.drawLine(20,60,20,64);
  u8g2.drawLine(15,55,11,55);
  u8g2.drawLine(25,55,29,55);
  u8g2.drawLine(22,54,25,47);
  u8g2.drawLine(25,53,29,50);
  u8g2.drawLine(16,53,12,50);
  u8g2.drawLine(18,51,16,47);
  u8g2.drawLine(16,58,12,60);
  u8g2.drawLine(18,60,16,63);
  u8g2.drawLine(25,58,29,60);
  u8g2.drawLine(22,60,25,63);
}

//========================================================
//            3. SETUP 함수 (초기화)
//========================================================
void setup() {
  // 시리얼 통신 시작 (통신 속도 115200bps)
  Serial.begin(115200);
  Serial.println("Battery level detection test starting...");

  // 부저 핀을 출력 모드로 설정
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BATTERY_PIN, INPUT);
  // OLED 디스플레이 초기화
  u8g2.begin();
}

//========================================================
//            4. LOOP 함수 (메인 로직)
//========================================================
void loop() {
  // 아날로그 핀에서 값을 읽어옴 (0 ~ 1023 범위)
  int analogValue = analogRead(BATTERY_PIN);

  // 아날로그 값을 전압으로 변환
  float measuredVoltage = (analogValue / 1023.0) * ANALOG_REFERENCE_VOLTAGE;

  // 저항 분배기 이득을 이용해 실제 배터리 전압 계산
  float batteryVoltage = measuredVoltage / POT_DIV;
  batteryVoltage = batteryVoltage * CALIBRATION_FACTOR; // 보정

  // 전압을 기준으로 배터리 잔량(%) 계산
  float batteryLevel = 0.0;
  if (batteryVoltage >= MAX_VOLTAGE) {
    batteryLevel = 100.0; // 전압이 최대치를 넘으면 100%로 표시
  } else if (batteryVoltage <= MIN_VOLTAGE) {
    batteryLevel = 0.0;   // 전압이 최소치보다 낮으면 0%로 표시
  } else {
    batteryLevel = ((batteryVoltage - MIN_VOLTAGE) / (MAX_VOLTAGE - MIN_VOLTAGE)) * 100.0;
  }

  // 시리얼 모니터에 현재 상태 출력
  Serial.print("Analog value: ");
  Serial.print(analogValue);
  Serial.print(" | Measured voltage: ");
  Serial.print(measuredVoltage, 2);
  Serial.print(" V | Actual voltage: ");
  Serial.print(batteryVoltage, 2);
  Serial.print(" V | Battery level: ");
  Serial.print(batteryLevel, 1);
  Serial.println(" %");

  // 배터리 잔량이 5% 미만일 경우 부저를 울림
  if (batteryLevel < LOW_BATTERY_THRESHOLD) {
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("Warning: Low Battery! Please charge or replace.");
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // OLED에 배터리 잔량 표시 함수 호출
  displayLevel((int)batteryLevel, batteryVoltage);

  // 1초마다 한 번씩 측정 및 업데이트
  delay(1000);
}