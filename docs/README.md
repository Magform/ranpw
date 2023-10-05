
# Ranpw

> A dynamic, Tamagotchi-inspired device developed in C++

## Introduction

The RANPW project aims to create a versatile, Tamagotchi-inspired tool enriched with a selection of games (LCatch, Pong, and LockY) and productivity applications (Cronometer and Termometer). This dynamic platform encourages high modularity, allowing individuals with basic C++ knowledge to develop and integrate their custom apps and games. RANPW operates on the mbed NXP LPC1768 microcontroller, coupled with the mbed application board.

### User Interaction Components

- **LCD (C12832):** The 32x128 pixel LCD display serves as the primary visual interface for all interactions within the application.

- **Joystick:** The joystick plays a pivotal role in navigating through all application interfaces.

- **Potentiometers:** Both potentiometers enhance specific user interactions, with one notably enhancing gameplay in the LockY game.

- **Temperature Sensor (LM75BD):** The LM75BD temperature sensor is utilized in the "Termometer" application to capture environmental temperature data.

- **Accelerometer (MMA7660):** The MMA7660 accelerometer contributes significantly to user interactions, particularly in the Hell and Pong games.