# Project Report in ET095G: RANPW

## Table of Contents

1. [Project Overview](#Project Overview)
2. [Used hardware and Library](#Used hardware and Library)
3. [Thread overview](Thread overview)
4. [Implementation Analysis](#Implementation Analysis)
5. [How to install](#How to install)
6. [Future improvements](#Future improvements)

## Project Overview

The central concept behind the RANPW project is to create a dynamic, Tamagotchi-inspired tool enriched with a selection of games (LCatch, Pong, and LockY) and productivity applications (Cronometer). This versatile platform encourages high modularity, enabling individuals with basic C++ knowledge to seamlessly develop and incorporate their custom apps and games. RANPW is designed to operate on the mbed NXP LPC1768 microcontroller, coupled with the mbed application board.

## Used hardware and Library

### LCD: C12832

The 32x128 pixel LCD display serves as the primary visual interface for all interactions within the application. To achieve seamless control over the display, I've customized the [C1832.h](https://os.mbed.com/teams/components/code/C12832/) library to ensure compatibility with the project's broader software ecosystem.

### Joystick

The joystick plays a pivotal role in navigating through all application interfaces. Its management is facilitated through the APIs provided directly by "mbed.h," which can be accessed [here](https://os.mbed.com/docs/mbed-os/v6.16/apis/index.html).

### Potentiometer

Both potentiometers are integral to specific user interactions, with one notably enhancing gameplay in the LockY game. The control of these potentiometers is streamlined through the APIs provided by "mbed.h," as detailed [here](https://os.mbed.com/docs/mbed-os/v6.16/apis/index.html).

### Accelerometer: MMA7660

The MMA7660 accelerometer contributes significantly to user interactions, particularly in the Hell and Pong games. To collect data from this component, the [MMA7660.h](https://os.mbed.com/teams/components/code/MMA7660/) library has been employed with slight modifications to align it with the project's requirements.

## Thread overview

At startup, RANPW initializes three distinct threads to manage various aspects of its functionality:

### Thread 1: User Interface and Interaction

This thread is responsible for overseeing the entire user interface and facilitating interaction with end-users. It dynamically creates and initializes instances of all apps and games while orchestrating their display on the LCD screen. Further insights into this thread's workings can be found in the Interaction.h and Interaction.cpp files.

### Thread 2: Kraken's Management

Thread 2 operates on a straightforward principle, employing basic rand() functions to introduce wait times of 1 to 5 minutes. During these intervals, it randomly decreases the pet's hunger by a value ranging from 1 to 5. Should the hunger level plummet to zero, the pet's life diminishes at varying rates—1, 2, or 3 points per minute. Conversely, if hunger surpasses 20, the pet gains 1 life point. Notably, both life and hunger levels have a cap of 25. Detailed insights into this thread's functionality are available in the live() function within Kraken.cpp.

### Thread 3: Data Saving Management

Thread 3 operates with a clear focus on data integrity. It consistently monitors the data stored in the members of the ConcurrentData structure. This structure is vital for ensuring safe data access across multiple threads. When disparities between the stored data and in-memory data are detected, Thread 3 takes action, overwriting the data and saving the respective file in the device's internal memory.

## Implementation Analysis

In the process of realizing the RANPW project, I've meticulously crafted 15 different classes to lay the foundation for its functionality and modularity. Each of these components plays a specific role in the project's architecture:

### ConcurrentData

This essential structure serves as the backbone for managing concurrent data access across multiple threads. It ensures data integrity and consistency, preventing conflicts and race conditions.

### DataSaver

The DataSaver class is responsible for handling data saving and data loading operations, ensuring that changes to critical data are persistently stored in the device's internal memory.

### Interaction

The Interaction class serves as the central hub for user interface management. It oversees the creation and initialization of app and game instances, orchestrates their display on the LCD screen, and manages user input via various hardware interfaces.

### Page

The Page class facilitates the organization and modularity of the code by providing a class where all the classes used within the page can be found

### Kraken

The Kraken class embodies the behavior and lifecycle of the virtual pet, monitoring key metrics such as hunger and life. It simulates the pet's interactions with the user.

### Menu

The Menu class, very similarry to Page, facilitates the organization and modularity of the code by providing a class where all the things on the Menu can be found.

### Bag

The Bag class manages the virtual inventory system, allowing users to collect and interact with food items within the application. It enhances gameplay and engagement.

### App

The Menu class facilitates the organization and modularity of the code by providing a class where all the different App are stored.

### Game

The Menu class facilitates the organization and modularity of the code by providing a class where all the different App are stored.

### Cronometer

The Cronometer is a specialized application designed to provide users with a versatile stopwatch.

### LCatch

LCatch is one of the interactive games featured in RANPW. It provides an engaging experience where users can test their reflexes and coordination.
What sets LCatch apart is its incremental speed feature, where the game progressively increases in difficulty as players successfully capture objects.

### LockY

LockY is another game that offers users a unique challenge. It leverages hardware components like potentiometers for gameplay.

### Pong

In Pong, player use the accelerometer as a unique input method to control the paddle and engage in the timeless challenge of bouncing a ball.

### Hell

Hell is a captivating minigame tucked within the RANPW project, offering a distinctive twist on the gaming experience. Unlike other games, Hell only surfaces when the Kraken's life reaches zero, triggering the Kraken's respawn process.
Distinguished by its lack of a tutorial, Hell immerses players in a realm where they need to discover how to play by hiself

### Temp

The Temp class represents a f component in the project's architecture. It serves as a versatile foundation for future developments and experimentation.

## How to install

### Binary

All that is necessary is to download the binary available [here](https://github.com/Magform/ranpw/releases) and then insert it into the internal storage of the microcontroller

### Compile yourself

To compile it yourself, I recommend following the official [embed OS CE wiki](https://github.com/mbed-ce/mbed-os) instead.
In particular I recommend, once the [development environment](https://github.com/mbed-ce/mbed-os/wiki/Toolchain-Setup-Guide) has been configured, you can chose to compile it:

- On the [command line](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-Command-Line)
- Using the [CLion IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-CLion)
- Using the [VS Code IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-VS-Code)

Remember that if you add something new to the project you need also to add it to the CMakeList.txt file

## Future improvements

### Fix Temp

Address issues in the "Temp" component to ensure its proper functionality and integrate it within the project.

### Code refactoring

Optimize and streamline the codebase with the following refactorings:

#### Remove Menu

Simplify the code structure by eliminating the "Menu" class and its associated classes ie Game ad App.
In this new approach, both games and apps will be managed in a manner similar to how apps are currently constructed and deconstructed when needed. This restructured approach simplifies the codebase and promotes memory efficiency.

#### Game as superclass

Consider redesigning all the game components to have a common superclass, promoting code reusability and consistency among different games.

#### App as superclass

Similarly, create a superclass for apps within the project to standardize their structure and behavior, making it easier to add new apps.

#### Doxygen documentation

### Add more app

#### Mouse

An app that give the ranpw the ability to simulate a mouse, users can interact with their computer systems by controlling the mouse cursor's movement and clicks directly from RANPW.

#### Rduck

An app that, give the script thanks to a USB stick, it allows the device, to emulate the behavior of a "Rubber Ducky.

### Music to evrything

Integrate music and sound effects into various aspects of the project to enhance the overall user experience and immersion.

#### Setting for music

Implement user settings that allow users to control music and sound effects, granting them the option to enable or disable audio as per their preference.

### Hardware

#### 3D printable Case

Design and create a 3D-printable case for the project.

#### Custom PCB

Make a custom PCB to integrate all the need hardware in a more compact manner.
