# WALL-E Robot Project

A modified and improved WALL-E robot project created by students at **Hongik University**.

This project is based on the excellent WALL-E project by **chillibasket** on Thingiverse:

* Original Project: [WALL-E Robot by chillibasket (Thingiverse #1159336)](https://www.thingiverse.com/thing:1159336)

Our team consisted of:

* 3 students from the College of Fine Arts
* 1 Mechanical Engineering student
* 1 Electrical & Electronic Engineering student

We combined our different areas of expertise to build and improve the original WALL-E design.

The goal of our modifications was mainly to improve:

* Long-term operational stability
* Internal hardware organization
* Battery monitoring
* Cooling
* Charging convenience
* Structural durability
* Storage and transportation

---

## Key Upgrades

### 1. Internal USB-C Charging Module

We added an internal charging module so that the battery can be charged without removing it from the robot.

A **USB-C charging module** was selected for convenience, and a small opening was added to the rear of the main body for access to the charging port.

---

### 2. Active Cooling System

The Raspberry Pi 3, buck converter, charging module, and other internal electronics generate a considerable amount of heat during operation.

To improve thermal management, we installed a cooling fan inside the robot.

The fan is connected to the main power circuit so that it automatically turns on when WALL-E is powered on.

The rear section of the main body was also redesigned to provide dedicated space for the fan.

---

### 3. Real-Time Battery Display

The battery monitoring code was improved to display:

* Battery voltage (`V`)
* Estimated remaining battery percentage (`%`)

in real time.

This makes it much easier to understand the current battery status while WALL-E is operating.

The related code and additional explanation can be found in the project blog posts linked below.

---

### 4. Load-Bearing Bracket Support

After installing all of the electronic components, we discovered that the original brackets were under too much stress and could break because of the increased weight.

To address this problem, we designed an additional part called:

**Bracket Support**

This part reinforces the bracket mounting area around the **Body Bottom** and helps distribute the load more safely.

---

### 5. Internal Circuit Management Stand

We designed a small table-like structure called the:

**Circuit Stand**

Its purpose is to organize the internal electronics and wiring more cleanly.

The stand includes multiple holes that allow wires to pass through and be routed more easily.

> **Note:**
> Once the robot is fully assembled, modifying the internal circuitry can be difficult.
> We recommend modifying the Circuit Stand or related parts to match your own hardware configuration before printing and final assembly.

---

### 6. OLED Frame Mounting Helper

We created an additional mounting helper to make it easier to securely install the OLED screen onto one of the remixed faceplates.

The helper can be attached to the original OLED frame using strong adhesive.

Afterward, the OLED display can simply be inserted into the supporter.

---

### 7. Custom Storage & Display House

Even after adding the Bracket Support, the brackets still experience significant stress from the robot's weight.

To protect the structure during storage and transportation, we designed a custom support structure called:

**WALL-E's House**

The house supports the area between the brackets and helps distribute the weight of the robot.

This provides a more stable way to:

* Store WALL-E
* Display WALL-E
* Transport WALL-E

without continuously loading the brackets.

---

## Assembly

The fundamental assembly and setup process is already documented extremely well by the original creator, **chillibasket**.

We strongly recommend reading the original project guide before starting this build.

During our project, we also used several useful parts created by other makers in the Thingiverse community.

The files shared with this project include:

* Original project parts
* Various remixed parts used during our build
* Parts modified by our team
* Completely new parts designed for our version

Before printing everything, we recommend checking both the original project page and its related remixes.

There are many useful ideas and improvements made by other creators.

---

## Important: STL Scaling

> **Added: 2025-10-05**

Some STL files may appear approximately **10 times larger than intended**.

This happened during the process of converting the original creator's mesh files into solid bodies in **Fusion 360**.

### Solution

Before printing affected parts, scale them to:

```text
10%
```

or:

```text
1/10 of the original imported size
```

Please check the dimensions of each part before starting a long print.

---

## Project Blog

A much more detailed build log is available on my personal Naver Blog.

The posts contain additional:

* Photos
* Circuit information
* Code explanations
* 3D modeling process
* Printing process
* Painting process
* Assembly process
* Videos of WALL-E in operation

### 1. WALL-E: Prologue

[Project] WALL-E: Prologue

https://blog.naver.com/zmmm777/223966100739

### 2. WALL-E: Circuit and Code Design

[Project] WALL-E: Circuit and Code Design

https://blog.naver.com/zmmm777/223996596107

### 3. WALL-E: 3D Modeling, Printing, Painting & Assembly

[Project] WALL-E: 3D Modeling, Printing, Painting & Assembly

https://blog.naver.com/zmmm777/224003324551

### 4. WALL-E: Final Photos & Review

**Recommended if you want to see the finished robot and final results.**

[Project] WALL-E: Final Photos & Review

https://blog.naver.com/zmmm777/224008998122

> The blog posts are written in Korean.
>
> Some of the original/base code is included without a detailed line-by-line explanation, so you may want to use it mainly as a reference for understanding the overall implementation.

---

## Credits

This project was a very fun and educational experience for our team.

Because students from several different majors worked together, each member was able to contribute their own expertise to the project.

Special thanks to the students from the **College of Fine Arts**, who did an amazing job painting and finishing the robot. Their work gave WALL-E much more character and brought the model to life.

Most importantly, a huge thank you to **chillibasket** for publishing the original WALL-E project.

We would also like to thank all of the creators in the Thingiverse community who shared useful remixed parts that helped us during the build.

We hope our modifications and documentation can also help or inspire other makers building their own WALL-E.

---

## Contact

If you have questions about the project, feel free to contact me through:

* Naver Blog comments
* Instagram: [@geo_.nhoyyy](https://www.instagram.com/geo_.nhoyyy/)

---

# 한국어 설명

이 WALL-E 로봇은 **홍익대학교 학생들의 팀 프로젝트**를 통해 제작되었습니다.

팀 구성은 다음과 같습니다.

* 미술대학 3명
* 기계공학과 1명
* 전자전기공학부 1명

각자의 전공 지식을 활용하여 WALL-E를 제작했습니다.

본 프로젝트는 **chillibasket님의 Thingiverse WALL-E 프로젝트**를 기반으로 제작되었습니다.

* 원본 프로젝트: [WALL-E Robot by chillibasket (Thingiverse #1159336)](https://www.thingiverse.com/thing:1159336)

기존 프로젝트를 기반으로 하되, 장시간 사용 시의 안정성과 사용 편의성을 높이기 위해 하드웨어 및 소프트웨어를 일부 수정했습니다.

---

## 주요 개선 사항

### 1. 내장형 USB-C 충전 모듈

배터리를 로봇에서 분리하지 않고 직접 충전할 수 있도록 내부에 충전 모듈을 추가했습니다.

사용 편의성을 위해 **USB-C 타입 충전 모듈**을 사용했으며, 본체 뒷면에는 충전 포트에 접근할 수 있는 작은 구멍을 추가했습니다.

---

### 2. 발열 관리를 위한 쿨링 팬

Raspberry Pi 3, Buck Converter, 충전 모듈 등 내부 전자부품에서 발생하는 열을 관리하기 위해 냉각 팬을 추가했습니다.

로봇의 메인 전원을 켜면 팬도 함께 작동하도록 회로를 구성했습니다.

이를 위해 본체 뒷면 구조를 수정하여 팬을 장착할 수 있는 별도의 공간을 만들었습니다.

---

### 3. 실시간 배터리 상태 표시

배터리 상태 확인 코드를 수정하여 다음 정보를 실시간으로 표시하도록 개선했습니다.

* 현재 배터리 전압 (`V`)
* 예상 배터리 잔량 (`%`)

이를 통해 로봇을 사용하는 동안 배터리 상태를 보다 직관적으로 확인할 수 있습니다.

관련 코드는 아래에 정리된 개인 블로그 게시글에서 확인할 수 있습니다.

---

### 4. 하중 보조 지지대 (Bracket Support)

모든 전자부품을 내부에 장착한 이후 WALL-E의 무게가 증가하면서 기존 Bracket이 하중을 견디지 못하고 파손되는 문제가 발생했습니다.

이를 해결하기 위해 **Bracket Support**라는 추가 부품을 설계했습니다.

이 부품은 `Body Bottom`의 Bracket 결합 부위를 추가로 지지하여 하중을 보다 안정적으로 분산시켜 줍니다.

---

### 5. 내부 회로 정리용 스탠드

복잡한 내부 회로와 배선을 깔끔하게 정리하기 위해 테이블 형태의 **Circuit Stand**를 제작했습니다.

여러 개의 구멍을 만들어 전선을 자유롭게 통과시키고 정리할 수 있도록 설계했습니다.

> **주의:**
> WALL-E를 완전히 조립한 이후에는 내부 회로를 다시 수정하기가 상당히 어렵습니다.
> 사용하는 부품과 회로 구성에 맞춰 Circuit Stand나 관련 모델을 수정한 뒤 출력하는 것을 권장합니다.

---

### 6. OLED 프레임 부착 서포터

리믹스 부품 중 하나인 OLED 부착판에 디스플레이를 더 쉽고 견고하게 장착할 수 있도록 별도의 서포터를 제작했습니다.

기존 OLED 프레임에 강력 접착제를 이용해 서포터를 부착한 뒤 OLED 디스플레이를 끼워 결합할 수 있습니다.

---

### 7. 맞춤형 보관 하우스 (WALL-E's House)

Bracket Support를 추가한 이후에도 WALL-E의 무게로 인해 Bracket에는 지속적으로 상당한 하중이 가해집니다.

따라서 WALL-E를 장기간 안전하게 보관하거나 운반하기 위한 전용 하우스를 제작했습니다.

하우스가 Bracket 사이의 공간을 지지하면서 로봇의 무게를 분산시켜 줍니다.

이를 통해 WALL-E를 보다 안정적으로:

* 보관
* 전시
* 운반

할 수 있습니다.

---

## 조립 안내

프로젝트의 기본적인 조립 및 설정 방법은 원작자인 **chillibasket님의 가이드**에 매우 상세하게 설명되어 있습니다.

따라서 본 프로젝트를 제작하기 전에 원본 프로젝트 페이지를 먼저 확인하는 것을 적극적으로 권장합니다.

또한 제작 과정에서 Thingiverse 커뮤니티의 여러 제작자분들이 만든 리믹스 부품들도 일부 활용했습니다.

본 프로젝트에서 공유하는 파일에는 다음 부품들이 포함되어 있습니다.

* 원작자 부품
* 제작 과정에서 사용한 리믹스 부품
* 저희 팀이 수정한 부품
* 저희 팀이 새롭게 설계한 부품

출력을 시작하기 전에 원본 프로젝트와 관련 Remix 페이지들도 함께 확인하는 것을 권장합니다.

다른 제작자들이 만든 좋은 아이디어와 개선 부품들이 많이 있습니다.

---

## 중요: STL 파일 스케일

> **2025-10-05 추가**

일부 STL 파일은 정상 크기보다 약 **10배 크게** 되어 있을 수 있습니다.

Fusion 360에서 원작자의 Mesh 파일을 Solid Body로 변환하는 과정에서 스케일이 10배 증가한 것이 원인입니다.

### 해결 방법

출력 전에 해당 모델의 크기를:

```text
10%
```

로 변경하거나,

```text
원본 크기의 1/10
```

로 축소해서 출력하면 됩니다.

장시간 출력이 필요한 부품은 반드시 출력 전에 치수를 확인하는 것을 권장합니다.

---

## 제작 과정 블로그

추가적인 제작 과정과 사진, 영상 등은 개인 네이버 블로그에 상세하게 정리해두었습니다.

다음과 같은 내용을 확인할 수 있습니다.

* 회로 설계
* 코드
* 3D 모델링
* 3D 프린팅
* 도색
* 조립
* 완성 사진
* WALL-E 작동 영상

### 1. WALL-E : 프롤로그

https://blog.naver.com/zmmm777/223966100739

### 2. WALL-E : 회로 및 코드 설계

https://blog.naver.com/zmmm777/223996596107

### 3. WALL-E : 3D 모델링 / 출력 / 도색 / 조립

https://blog.naver.com/zmmm777/224003324551

### 4. WALL-E : 결과물 사진 촬영 및 후기

**완성된 WALL-E의 사진과 작동 모습을 보고 싶다면 이 글을 가장 추천합니다.**

https://blog.naver.com/zmmm777/224008998122

블로그 게시물은 한국어로 작성되어 있습니다.

또한 일부 기본 코드에 대해서는 코드 전체를 한 줄씩 설명하지 않았으므로 전체적인 구현 방식과 아이디어를 참고하는 용도로 활용하는 것을 권장합니다.

---

## Credits

다양한 전공의 학생들이 함께 프로젝트를 진행하며 즐겁게 제작하고 많은 것을 배울 수 있었습니다.

특히 미술대학 팀원들이 WALL-E의 도색과 마감을 훌륭하게 작업해 준 덕분에 로봇이 훨씬 더 생동감 있는 모습으로 완성될 수 있었습니다.

무엇보다 훌륭한 WALL-E 프로젝트를 공개해 주신 **chillibasket님께 감사드립니다.**

또한 유용한 Remix 부품을 공개해 주신 Thingiverse의 모든 제작자분들께도 감사드립니다.

저희의 수정 사항과 제작 기록이 다른 제작자분들의 WALL-E 제작에도 조금이나마 도움이 되기를 바랍니다.

---

## Contact

프로젝트에 대해 궁금한 점이 있다면 다음 방법으로 연락해 주세요.

* 네이버 블로그 댓글
* Instagram: [@geo_.nhoyyy](https://www.instagram.com/geo_.nhoyyy/)
