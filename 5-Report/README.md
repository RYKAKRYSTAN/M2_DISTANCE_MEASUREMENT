
***ABSTRACT***<br/>
            This project uses an ultrasonic senor(Hd44780) to measure distance with ATmega 328 microcontroller.The sensor works in such a way that the sensor sends an ultrasonic 
          pulse if any object is being sensed the pulse bounces back to the sensor.Ultrasonic sensors are a great solution for the detection of clear objects.  For liquid level 
          measurement, applications that use infrared sensors, for instance, struggle with this particular use case because of target translucence. 
          
# Distance Measurement using ATmega328 
## Introduction
Distance measurement using HC-SR04 and ATMEGA328p. In this project I have measured distance in centimetres, with the help of HC-SR04 Ultrasounic sensor, ATMEGA328 microcontroller, LCD Display via USART 

## Research
In this project, the Ultrasounic sensor uses a technique called “ECHO” which is something you get when sound reflects back after striking with a surface. We know that sound vibrations can not penetrate through solids. So what happens is, when a source of sound generates vibrations they travel through air at a speed of 220 meters per second. These vibrations when they meet our ear we describe them as sound. As said earlier these vibrations can not go through solid, so when they strike with a surface like wall, they are reflected back at the same speed to the source, which is called echo. Ultrasonic sensor “HC-SR04” provides an output signal proportional to distance based on the echo. The sensor here generates a sound vibration in ultrasonic range upon giving a trigger, after that it waits for the sound vibration to return. Now based on the parameters, sound speed (220m/s) and time taken for the echo to reach the source, it provides output pulse proportional to distance.

## Features
- **Microcontroller     :** ATmega328
- **Operating Voltage   :** 5V
- **Program Memory Type :** Flash
- **Flash Memory        :** 32Kbytes
- **SRAM                :** 2 KB (ATmega328)
- **EEPROM              :** 1 KB (ATmega328)

## SWOT Analysis
![swot](https://user-images.githubusercontent.com/101057218/164680540-1808dd1b-794e-4fbe-a098-5945b3d87587.jpg)


## 4W's and 1H
## Who :
Any layman without the knowledge of embedded system.

## What :
Distance measurement of objects with the help of HC-SR04 Ultrasounic sensor, ATMEGA328 microcontroller, LCD Display via USART

## When :
To detect or locate  a distabt object

## Where :
It can be used by industries where distance measurement plays a vital role.

## How :
It is Activated by generating a acoustic piuse
## Detail Requirements
## High Level Requirements
|ID  |Description      |Status     |
|----|-----------------|-----------|
|HLR1|Microcontroller  |Implemented|
|HLR2|Ultrasonic Sensor|Implemented|
|HLR3|Display          |Implemented|
|HLR4|Software         |Implemented|

## Low Level Requirements
|ID       |Description                             |Status     |
|---------|----------------------------------------|-----------|
|HLR1_LLR1|ATmega328                               |Implemented|
|HLR2_LLR1|HC-SR04                                 |Implemented|
|HLR3_LLR1|LCD Display                             |Implemented|
|HLR4_LLR1|Visual Studio Code with AVR GCC compiler|Implemented|
|HLR4_LLR2|SimulIDE                                |Implemented|

## Behavioural diagram
![BHD1](https://user-images.githubusercontent.com/101564345/164682490-de7c0284-b717-4418-980e-e6a50a174e21.png)
## Structural diagram
![structural](https://user-images.githubusercontent.com/101564345/164683247-efe6f22d-f416-45dc-9395-af6a7f82b68b.jpg)


