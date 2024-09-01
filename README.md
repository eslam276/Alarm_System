
# Alarm System Using STM32F103C8T6 and STM32F446RE

## Project Overview

This project is an alarm system developed using the Bluepill board (STM32F103C8T6), Nucleo board (STM32F446RE), and other components like the Putty application and Real-Time Clock (RTC) module DS1307. The system is designed to provide time-based functionalities, including setting alarms and displaying time and date.

### Team Members:
1. Eslam Nasr
2. Mahmoud Haez
3. Yousef Elbadawy

## Hardware and Drivers

### Nucleo Board (STM32F446RE)
- **Drivers Used:**
  - GPIO
  - RCC
  - USART
  - SYSTICK
  - I2C
  - DS1307 (RTC)

### Bluepill (STM32F103C8T6)
- **Drivers Used:**
  - GPIO
  - RCC
  - USART
  - SYSTICK
  - CLCD (Character LCD)
  - LED
  - Buzzer

## Communication Protocols

- **UART Communication:**
  - Between Bluepill and Nucleo board
- **I2C Communication:**
  - Between Nucleo board and RTC (DS1307)
- **USB-to-Serial Communication:**
  - Between Nucleo board and laptop using USB-TTL based on UART

## Functionalities

1. **User Login:**
   - On starting the project, the user must log in by entering their ID and password.
   - Users have 3 attempts; after that, the system shuts down, and the red LED is turned on.
   - On entering incorrect credentials, appropriate error messages are displayed:
     - Incorrect ID: "ID invalid"
     - Incorrect Password: "Password invalid"
     - Both incorrect: "ID invalid and Password invalid"
   - Successful login turns on the green LED and allows further interactions.

2. **Initial Setup:**
   - After a successful login, the user is prompted to set the date and time for the first time and choose between a 12-hour or 24-hour format.

3. **Main Menu:**
   - The following options are presented on the Putty terminal:
     1. Display time and date
     2. Set time and date
     3. Set Alarm
     4. Exit
   - Entering an invalid number prints "Please enter a valid number..."

4. **Display Time and Date:**
   - The current date and time are displayed on both the Putty terminal and the CLCD on the Bluepill board.

5. **Set Alarm:**
   - The user can set up to 5 alarms.
   - When an alarm time is reached, the system prints an alarm notification on the terminal, toggles the blue LED, and activates the buzzer.

## Debugging

- A logic analyzer was used to debug and monitor the data transmitted via UART communication.

## Project Setup

### Prerequisites

1. **Hardware:**
   - STM32F103C8T6 Bluepill Board
   - STM32F446RE Nucleo Board
   - DS1307 RTC Module
   - Character LCD (CLCD)
   - Buzzer
   - LEDs (Red, Green, Blue)
   - USB-TTL Converter

2. **Software:**
   - [Putty](https://www.putty.org) for serial communication.
   -  STM32CubeIDE for development.

### Steps to Run the Project

1. Connect the Bluepill and Nucleo boards as per the specified UART and I2C connections.
2. Power up the boards and open the Putty terminal.
3. Follow the login process on the terminal.
4. Set up the initial time and date and navigate through the main menu.



## Conclusion

This alarm system effectively integrates embedded systems programming, communication protocols, and debugging techniques to provide a reliable and user-friendly time-based alarm functionality.

