# Discussion

## 1 Optimization

Given the scope of this project, ensuring optimal resource utilization became a crucial aspect of development.
To achieve this, I delved into various optimization techniques to maximize the efficiency of the system. Several key strategies were implemented:

- **Global Initialization:** To minimize memory usage, I opted to initialize certain variables and resources globally in the main function. This approach prevented them from being allocated in the .bss section and instead placed them in the stack, reducing the overall memory footprint.

- **Sensor Initialization:** I centralize sensor initialization within a dedicated class, initializing sensors only once and passing their pointers where needed throughout the project. This approach eliminates redundant sensor reinitialization, conserving more memory

- **Scoped Game Initialization:** To further optimize memory allocation, I strategically limited the scope of game initialization. Games are initialized only when required, ensuring they occupy memory space only when actively in use.

- **Pointer Management:** Ensuring the absence of dangling or unclean pointers was paramount.

## 2 Future plan


### 2.1 Secure data storage

Enhance data security by implementing minor encryption measures for all saved data. This safeguard prevents unauthorized user modifications and ensures data integrity.

### 2.2 Code refactoring

Optimize and streamline the codebase with the following refactorings:

#### Game as superclass

Consider redesigning all the game components to have a common superclass, promoting code reusability and consistency among different games.

#### App as superclass

Similarly, create a superclass for apps within the project to standardize their structure and behavior, making it easier to add new apps.

#### Doxygen documentation

### 2.3 Add more app

### 2.4 Music to evrything

Integrate music and sound effects into various aspects of the project to enhance the overall user experience and immersion.

#### Setting for music

Implement user settings that allow users to control music and sound effects, granting them the option to enable or disable audio as per their preference.

### 2.5 Hardware

#### 3D printable case

Design and create a 3D-printable case for the project.

#### Custom PCB

Make a custom PCB to integrate all the need hardware in a more compact manner.
