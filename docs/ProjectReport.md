# Project Report in ET095G: RANPW

Nicolas Ferraresso

## Introduction
The main idea behind this project is to develop a tool similar to a Tamagotchi, equipped with some games (LCatch, Pong, and [LockY]) and some apps (Cronometer, thermometer, [MMake], [Mouse], [RDuk]). This tool should also have high modularity so that anyone with basic knowledge of C++ can create and add their own app or game with relative ease.
In particular, at startup, three different threads are launched: one containing the main application, one handling the hunger and life loss of the Kraken, and a third managing data saving.
### Thread 2
Thread 2 is quite simple. It uses basic rand() functions to wait for a certain number of minutes between 1 and 5 and then reduces hunger by a random number between 1 and 5. If hunger reaches 0, life decreases by 1, 2, or 3 points every minute. Additionally, if hunger is greater than 20, life increases by 1 point. The maximum values for life and hunger are both 25.
### Thread 3
Thread 3 is also relatively simple. It continuously checks the data stored in the members of the DataToSave structure in ConcurrentData format (to ensure correct access from multiple threads). If it detects that these values differ from those currently saved in memory, it overwrites them and saves the respective file in the device's internal memory. Of course, the read and write system includes a very basic encryption system to prevent modification of the saved values by an inexperienced user. At startup, the thread reads the data from the save file and loads it into the structure from which all other classes can retrieve previously saved data.
### Thread 1
This thread directly manages the entire interface and interaction with the end user, creating and initializing instances of all apps and games and handling their display on the screen. To better understand what this thread does, it is recommended to take a look at Interaction.h and Interaction.cpp.

## Implementation Analysis

### LCD: C12832
This 32x128 pixel LCD monitor serves as the visual display for all aspects of the application. To control it, I've customized the [C1832.h](https://os.mbed.com/teams/components/code/C12832/) library, ensuring compatibility with the rest of my software.
LCD monitor 32x128 pixel, used for all the visualization of the application.

### Joystick
The joystick plays a pivotal role in navigating through all application interfaces. Its management is facilitated through the APIs provided directly by "mbed.h," which can be accessed [here](https://os.mbed.com/docs/mbed-os/v6.16/apis/index.html)

### Potentiometer [TBI]
I am using the two potentiometers to manage certain user interactions, especially within the MMake app and the LockY game.

### Temperature Sensor: LM75BD 
A temperature sensor used in the thermometer.

### Buzzer [TBI]
Used for the sounds produced by MMake.

### Accelerometer: MMA7660 [TBI]
Used for mouse control.

### USB output [TBI]
Used to communicate application mouse and RDucky commands to the computer.

### USB input [TBI]
Used to insert RDucky plugins.

## Problem
File never closed
A lot of pointer never cleared

## Poblem to fix
Pass temp sensor
Pong+LCatch

## Other improvement
Music to evrything (With setting to set it of)