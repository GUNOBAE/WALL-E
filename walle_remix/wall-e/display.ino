/**
 * oLED Display
 *
 * @file      display.ino
 * @brief     Draw battery level on the oLED display
 * @author    Hans Vandamme
 * @copyright MIT license
 * @version   1.0
 *
 * Code to draw the battery level indicator onto an oLED
 * display. For instructions of how to wire up the display,
 * see the README file included in this repository.
 */

#ifdef OLED

/**
 * 배터리 잔량, 전압, 아이콘을 디스플레이에 그림.
 * * @param batlevel 현재 배터리 퍼센트
 * @param voltage 현재 배터리 전압
 */
void displayLevel(int batlevel, float voltage) {
  u8g2.firstPage();
  do {
    u8g2.setDrawColor(1);
    drawSun();

    // 10% 단위로 막대 그래프 표시
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
    u8g2.setFont(u8g2_font_5x8_tr);
    char volt_buf[10];
    dtostrf(voltage, 4, 2, volt_buf);
    strcat(volt_buf, "V");
    u8g2.drawStr(42, 62, volt_buf);

    // 2. 퍼센트 값 표시 (큰 폰트)
    u8g2.setFont(u8g2_font_ncenB10_tr);
    char level_buf[10];
    sprintf(level_buf, "%d %%", batlevel);
    u8g2.drawStr(80, 62, level_buf);

  } while ( u8g2.nextPage() );
}

/**
 * 배터리 잔량 막대를 그리는 함수들
 */
void drawBatt10() { u8g2.drawBox(108,0,16,40); }
void drawBatt20() { u8g2.drawBox(96,0,7,40); }
void drawBatt30() { u8g2.drawBox(84,0,7,40); }
void drawBatt40() { u8g2.drawBox(72,0,7,40); }
void drawBatt50() { u8g2.drawBox(60,0,7,40); }
void drawBatt60() { u8g2.drawBox(48,0,7,40); }
void drawBatt70() { u8g2.drawBox(36,0,7,40); }
void drawBatt80() { u8g2.drawBox(24,0,7,40); }
void drawBatt90() { u8g2.drawBox(12,0,7,40); }
void drawBatt100() { u8g2.drawBox(0,0,7,40); }

/**
 * 태양 아이콘을 그리는 함수
 */
void drawSun() {
  u8g2.drawDisc(20, 55, 3); u8g2.drawLine(20,50,20,46); u8g2.drawLine(20,60,20,64);
  u8g2.drawLine(15,55,11,55); u8g2.drawLine(25,55,29,55); u8g2.drawLine(22,54,25,47);
  u8g2.drawLine(25,53,29,50); u8g2.drawLine(16,53,12,50); u8g2.drawLine(18,51,16,47);
  u8g2.drawLine(16,58,12,60); u8g2.drawLine(18,60,16,63); u8g2.drawLine(25,58,29,60);
  u8g2.drawLine(22,60,25,63);
}

#endif /* OLED */