# WALL-E Robot Project

🌐 **Language:** **English** | [한국어](README_KR.md)

<p align="center">
 <img width="773" height="515" alt="image" 
  src="https://github.com/user-attachments/assets/1f5a06a1-48de-4d34-9912-d39e4e6716e7" />
 <br>
 <sub>Completed WALL-E</sub>
</p>

<p align="center">
 <img width="400" height="400" alt="image" 
  src="https://github.com/user-attachments/assets/eb8087c5-d2b3-4a41-b8f8-56168610d778" />
</p>

This is a **WALL-E robot project** built by five students from Hongik University.

The project is based on **chillibasket's open-source WALL-E project**. Instead of simply reproducing the original design, we modified parts of the circuit, code, and 3D models, and designed several new components to solve problems we encountered during the actual build.

Our team consisted of three students from art and design fields, one Mechanical Engineering student, and one Electrical & Electronic Engineering student.

---

## About the Project

This was my first personal robotics project where I actually built something using knowledge that I had previously only learned in theory.

Before starting this project, I had studied topics such as electronics, programming, and Arduino, but I had never gone through the experience of designing and completing something from scratch.

So rather than simply building WALL-E, my main goal was to experience the entire process of:

> **Planning → Designing → Building → Failing → Improving → Completing**

WALL-E already had great open-source resources and many existing builds, which made it a good choice for my first project.

Instead of starting completely from zero, I used the existing project as a foundation and focused on modifying, improving, and solving the parts that did not fit our build.

---

## Main Features

<p align="center">
 <img width="773" height="433" alt="image" src="https://github.com/user-attachments/assets/d088ae7b-4c70-4656-93cd-4beaf823789d" />
</p>

The completed WALL-E includes the following features:

* Remote control through a Raspberry Pi-based web server
* Driving using two DC motors
* Control of seven servo motors through a PCA96875A

  * Head
  * Neck
  * Eyes
  * Both arms
* Real-time battery status display on an OLED **(added feature!)**

  * Current voltage (`V`)
  * Estimated remaining battery percentage (`%`)
* Battery level graphics similar to the original WALL-E interface
* Internal USB-C battery charging
* Rear cooling fan for thermal management of the internal electronics

---

# Circuit Diagram & Improvements

<p align="center">
 <img width="500" height="300" alt="image" src="https://github.com/user-attachments/assets/b84e7679-fc1d-40e1-a142-1b987f3a5853" />
 <br>
 <sub>Circuit Diagram</sub>
</p>

## 1. Real-Time Battery Status Display

This is the voltage measurement circuit that was included as an optional feature in the original project.

<p align="center">
 <img width="500" height="378" alt="image" src="https://github.com/user-attachments/assets/16182dd6-8ccf-4d02-b018-718567d266a2" />
</p>

<p align="center">
 <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/60998b3a-a274-4fc0-a68c-9fd9f6538fcc" />
 <img width="386" height="386" alt="image" src="https://github.com/user-attachments/assets/82473485-194a-48dc-a951-b5728d99f3df" />
</p>

I first tested the circuit on a breadboard and then moved it onto a prototyping board.

I also wrote code so that the OLED could display the following information in real time:

* Battery voltage
* Estimated remaining battery percentage
* Low-voltage status

This makes it much easier to check WALL-E's battery status while it is running.

I also recreated the battery graphic so that it looks similar to WALL-E's original battery interface!

More details about the resistor-based battery measurement circuit and code can be found in this blog post:

https://blog.naver.com/zmmm777/223961405857

> Personally, I think using something like an INA219 would be an easier way to measure the battery. It is not a particularly expensive module either!

---

## 2. Internal USB-C Charging

Originally, the battery had to be removed from inside WALL-E whenever it needed to be charged.

<p align="center">
 <img width="400" height="400" alt="image" src="https://github.com/user-attachments/assets/6846bde4-639e-48d9-a4e7-7edad2accfbc" />
</p>

To make charging more convenient, we installed an internal **USB-C charging module compatible with the 3S battery**.

We also added an opening to the rear body so that the USB-C charging port can be accessed without disassembling WALL-E.

> When choosing a charging module, make sure it matches both the cell configuration and charging current requirements of your battery.

---

## 3. Internal Cooling Fan

Because the Raspberry Pi, buck converters, USB-C charging module, and other electronics were packed into a relatively small space, a significant amount of heat accumulated inside the body.

The Raspberry Pi and charging module in particular became quite hot, so we modified the Body Back and added a cooling fan.

The fan is connected to the main power switch, so it automatically turns on whenever WALL-E is powered on.

---

## 4. Bracket Support

After installing the battery and all of the electronic components, WALL-E became considerably heavier, which placed a large load on the lower brackets.

I thought the brackets could eventually fail under long-term use, so I designed an additional **Bracket Support** to reinforce the bracket mounting points on the Body Bottom.

The support uses an arch-shaped structure to help distribute the load around the bracket area.

---

## 5. Circuit Stand

The internal space inside WALL-E is quite limited.

At the time of this project, I used connectors and crimp terminals for many of the electrical connections instead of soldering them directly.

This made the circuit easier to modify, but the wiring and connectors took up much more space than I expected.

To organize everything more cleanly, I designed a multi-level **Circuit Stand**.

The components were roughly arranged like this:

```text
3rd Floor : Servo Shield / Arduino
2nd Floor : Raspberry Pi
1st Floor : Connectors / Buck Converter / Power Circuit
```

Each layer has multiple holes so that wires can be routed between the different levels.

> If I were to build this again, I would reduce the number of connectors and use more soldered connections with heat-shrink tubing. That would significantly reduce the amount of space taken up by the wiring.

---

## 6. OLED Frame Supporter

The original OLED Frame did not have a structure that securely held the OLED module itself.

To mount the OLED more firmly, I designed an additional **OLED Frame Supporter**.

The supporter is glued onto the original OLED Frame, and the OLED module can then be inserted and held in place.

---

## 7. Track / Motor Bracket Improvements

Some of the connection structures in the original Track design were not very strong when printed in PLA and could break relatively easily.

Because of this, we used a **pin-based Track Remix** shared by another maker in the Thingiverse community.

For the Motor Bracket, we also used another creator's one-piece design instead of the original split bracket.

Throughout the project, we tested not only the original parts but also several community-made remixes and selected the parts that worked best for our actual build.

---

## 8. WALL-E's House

Even after adding the Bracket Support, WALL-E's weight was still constantly applied to the brackets while the robot was being stored.

To reduce this load during storage and transportation, I designed a dedicated support structure called **WALL-E's House**.

The house supports the center of WALL-E's lower body and helps distribute its weight.

It is mainly intended for:

* Long-term storage
* Display
* Transportation

This helps reduce the continuous stress placed on the brackets.

---

# Hardware

The main components used in this project are listed below.

| Category         | Component                     |
| ---------------- | ----------------------------- |
| Main Computer    | Raspberry Pi 3                |
| Controller       | Arduino                       |
| Battery          | 11.1V 3S Battery              |
| Servo Control    | 16 Channel Servo Motor Shield |
| Servo Motors     | 7 × SG90S                     |
| Drive            | 2 × DC Motor                  |
| Display          | OLED                          |
| Power Regulation | Buck Converter                |
| Charging         | USB-C 3S Charging Module      |
| Cooling          | DC Cooling Fan                |

Battery power was divided into three main power lines.

```text
11.1V 3S Battery
│
├── DC Motor Line
│     └── Drive Motors
│
├── 5V Controller Line
│     ├── Raspberry Pi
│     └── Arduino
│
└── 5V Servo / Auxiliary Line
      ├── Servo Motors
      ├── OLED
      └── Cooling Fan
```

Based on the maximum load calculation at the time of the project, the estimated total peak current consumption was approximately **7.43A**.

Using a simple calculation with a 2.4Ah battery, the theoretical operating time at maximum load is approximately **19 minutes**.

However, not every component continuously operates at maximum load during real use, and in actual testing WALL-E usually ran for approximately **30–50 minutes**.

---

# Software

The software was modified from chillibasket's original WALL-E code.

### Original

[chillibasket/walle-replica](https://github.com/chillibasket/walle-replica)

The project builds on several features already provided by the original implementation:

* Arduino-based servo and motor control
* Raspberry Pi-based web server
* Remote control interface
* WALL-E animations

We then added or modified several parts of the software for our own build.

The main changes include:

* Real-time battery voltage measurement
* Battery percentage estimation
* OLED output
* Pin configuration changes for our hardware
* Modified and additional animations

Each servo motor was calibrated before final assembly.

After WALL-E is fully assembled, accessing the Servo Horns and Linkages becomes much more difficult, so I strongly recommend checking and confirming all calibration values **before final assembly**.

---

# 3D Modeling & Printing

This project was not modeled completely from scratch.

We used a combination of:

* Original Parts
* Thingiverse Remix Parts
* Parts modified by us
* Completely new parts designed for this project

The 3D models used for the project are also organized on Thingiverse.

**Thingiverse**

https://www.thingiverse.com/thing:7141470

Some of the representative parts that we modified or designed ourselves include:

* Bracket Support
* Circuit Stand
* OLED Frame Supporter
* Cooling Fan Mount
* USB-C Charging Port
* WALL-E's House

---

## ⚠️ Important: STL Scaling

Some STL files were converted from the original Mesh files into Solid bodies in Fusion 360.

During this conversion process, several files became approximately **10 times larger than their intended size**.

If you encounter one of these files, change the scale in your slicer to:

```text
Scale = 10%
```

Before starting a long print, I strongly recommend checking the actual dimensions of the model first.

---

# Problems & Lessons Learned

I probably learned more from the problems and mistakes that happened during this project than from the finished robot itself.

## Power Design and Current Capacity

At first, when choosing a buck converter, I focused mainly on matching the output voltage and did not pay enough attention to the maximum current required by the system.

Because of this, the original 3A converter could not provide enough current, and I eventually had to replace it with 5A converters.

After that, I started calculating the maximum current consumption of each component, including values such as servo stall current, before choosing power components.

This taught me that power system design is not just about matching voltage.

You also need to consider **the total load and maximum current requirements of the system**.

---

## Raspberry Pi ↔ Arduino Communication Noise

To reduce the amount of space used inside the robot, I once replaced the Raspberry Pi-to-Arduino communication cable with shorter ordinary wires.

After doing that, communication errors increased significantly.

When I switched back to the original cable, communication returned to normal.

This was a useful lesson that even a small wiring change can affect signal quality and electrical noise.

---

## The Importance of Prototyping

At the beginning of the project, I printed many of the parts at full size and immediately started assembling them.

However, as the design changed and we started using different Remix parts, some components that had already been printed and painted had to be thrown away and printed again.

If I were to do this project again, I would first print scaled prototypes or only the minimum necessary test parts to verify:

* Interference between parts
* Whether the parts can actually be assembled
* Available wiring space
* Sensor and electronic component placement

Only after verifying those points would I begin the final prints.

---

## Internal Wiring

Because this was my first project, I relied heavily on connectors and crimp terminals instead of soldering.

This made the circuit easier to modify during development, but during final assembly I realized that the connectors took up a surprisingly large amount of space.

I learned that when designing a small robot, it is important to consider not only the circuit itself, but also **wire length, connector size, cable routing, and maintainability as part of the mechanical design**.

---

## Faulty Components and Debugging

During the project, I spent a significant amount of time debugging problems caused by faulty components such as Servo Shields and Charging Modules.

At first, I assumed that my circuit or code was wrong.

After repeated testing, however, some of the problems turned out to be caused by the hardware itself.

Because of this experience, I now think it is very important to test each individual module separately before connecting and integrating the entire system.

---

# Final Thoughts

The goal of this project was never to build the most technically complex robot possible.

The most important thing for me was simply **experiencing what it is like to build something from start to finish**.

Before this project, I had a vague fear of starting real projects.

Studying theory and following example code felt very different from staring at a blank page and trying to create an actual working system from scratch.

While building WALL-E, I experienced circuit design, power distribution, Raspberry Pi, Arduino, 3D modeling, 3D printing, wiring, soldering, assembly, and debugging for the first time in a real project.

Most importantly, by running into countless problems that did not go according to plan and solving them one by one, I was able to get rid of much of that fear of starting projects.

I think that was the biggest result of this project.

This WALL-E project became the starting point for the robotics projects I want to build next.

---

# Team

This project was completed by five students from Hongik University.

| Field                               | Members |
| ----------------------------------- | ------: |
| Mechanical Engineering              |       1 |
| Electrical & Electronic Engineering |       1 |
| Art & Design                        |       3 |

We divided the work across areas such as mechanical design, circuits, programming, 3D modeling, printing, assembly, and painting.

In particular, the painting and finishing work done by the Art & Design members made a huge difference in the overall quality and appearance of WALL-E.

---

# Credits

This project is based on **chillibasket's WALL-E project**.

A huge thank you to chillibasket for sharing the original project, source code, and detailed build guide.

We also used several Remix parts shared by makers in the Thingiverse community during the build.

Thank you to everyone who designed and publicly shared those parts.

We would also like to thank **Hongik University Maker Space**, **ATOM Club**, and everyone else who helped us by providing access to 3D printers, workspace, equipment, and support throughout the project.

---

# Detailed Build Logs

More detailed information about the build process, problems, circuit design, code, photos, and videos can be found on my personal blog.

### 1. WALL-E: Prologue

Why I started the project, project goals, team organization, and initial plans

https://blog.naver.com/zmmm777/223966100739

### 2. WALL-E: Circuit & Code Design

Circuit design, power system, Raspberry Pi, Arduino, battery monitoring, and code

https://blog.naver.com/zmmm777/223996596107

### 3. WALL-E: 3D Modeling / Printing / Painting / Assembly

3D model modifications, Remix parts, newly designed parts, printing, and assembly

https://blog.naver.com/zmmm777/224003324551

### 4. WALL-E: Final Photos & Project Review

Final WALL-E photos, driving videos, and my thoughts after completing the project

https://blog.naver.com/zmmm777/224008998122

> The blog posts are written in Korean and contain much more detailed build logs and troubleshooting notes than this README.

---

# Contact

If you have any questions about the project, feel free to contact me through:

* Naver Blog comments
* Instagram: [@geo_.nhoyyy](https://www.instagram.com/geo_.nhoyyy/)
