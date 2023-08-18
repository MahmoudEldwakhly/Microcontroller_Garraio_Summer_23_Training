# Microcontroller_Garraio_Summer_23_Training
Summer 2023 Training Introduction to Embedded Systems on Microcontroller Tiva C Board Texas Instrument 

Beginning on a voyage into the world of microcontroller applications and embedded systems with the enlightening Microcontroller Garraio Summer 2023 Training.On the tiva c board, Learning different concepts and gain experience with dealing with datasheets.


Course Highlights:

1. Register/API Level Applications:
Delve into the heart of microcontroller programming by mastering register and API-level applications. Learn to communicate directly with hardware components using registers and manipulate them through Application Programming Interfaces (APIs) to achieve precise control.

2. Driver Library Implementation:
Grasp the essentials of driver libraries, like the TIVAWARE library, which streamlines microcontroller programming. Explore the architecture and development of driver libraries that simplify complex hardware interactions, making peripheral interfacing more accessible.

3. GPIO (General Purpose Input/Output):
Discover the adaptability of GPIO pins in microcontroller applications. Gain hands-on experience configuring GPIO pins for both input and output operations. Interface with many electronic external devices like (LEDs, potentiometer) creating interactive applications.

4.SysTick Timer:
Explore the SysTick timer, an essential tool for system scheduling and timekeeping. Learn how to utilize this versatile timer to create precise timing intervals for various microcontroller tasks.

5. GPTM (General-Purpose Timer Module):
Understand time management within microcontroller systems through the General-Purpose Timer Module. Learn to utilize timers for tasks such as generating delays, measuring time intervals, and synchronizing system processes.

6. I2C (Inter-Integrated Circuit):
Master the I2C communication protocol, which is essential for connecting microcontrollers and peripheral devices. Explore master-slave communication and data transmission.

7. ADC (Analog-to-Digital Converter) Peripherals:
Convert analog signals into digital data with ADC peripherals. learning it is identification and Initialization on board. Learn the concept well by making a project. 

8. UART (Universal Asynchronous Receiver-Transmitter):
Uncover the power of UART communication for serial data transmission. Explore asynchronous communication fundamentals and learn to implement UART to connect microcontrollers and external devices.

9. EEPROM (Electrically Erasable Programmable Read-Only Memory):
Dive into the world of EEPROM and understand how to store and retrieve data even when power is removed. Explore non-volatile memory solutions for preserving critical information in various applications.

10. DMA (Direct Memory Access):
Discover the efficiency of DMA in data transfer. Learn how to offload data movement tasks from the CPU to dedicated DMA channels, improving system performance. Write and Read data from it

Outcome:
creating a unique project for each topic and Making a final project at the end of training familiar with these various topics together.

Projects : 

1- When any Switch of tiva is pressed Whitle led is turned on.
2- Blinking LED every 0.5 second, 1 second, 2.5 seconds, 10 seconds using (Systic timer,Timers,Interupt).
3- Using keypad as a calculater (By using INTERUPT & UART).
4- ADC - Using potentiometer -> led on and off by potentiometer and UART for printing values changed by potentiometer.
5- Using I2C Between two tiva boards (Togglling a led on tiva board by the button of the other tiva board).
6- Using UDMA and EEPROM.
7- Final project : 

project overview : 

1- Set the normal traffic light:
Use one of the timers to have the two car traffic lights working. The traffic light shall stay GREEN for 5 seconds, then YELLOW for 2 seconds, then turns RED. When one of the traffic lights is set to RED the other one has to go GREEN exactly after 1 second. The same sequence then is repeated again.
GREEN : 5 seconds YELLOW: 2 seconds Then RED. Wait 1 second, then start the sequence on the other traffic.
2- Implement the pedestrian traffic light:
Use two push buttons and 4 LEDs for this system. There will be two pedestrian traffic, each with a push button and 2 LEDS: GREEN and RED. Whenever a pedestrian presses the button, the traffic light that is green shall be interrupted, and the pedestrian traffic light will be green for 2 seconds. Then it will be back to RED and the traffic light that was interrupted will resume from when it was paused.
Example: If the car traffic light was green for 2 seconds and interrupted it will then resume the remaining 3 seconds to finish the 5 seconds.

3- UART
Send the current state of the whole system via UART whenever the system changes its state. The possible states, for example, are CARS NORTH SOUTH, CARS EAST WEST, PEDESTRIAN NORTH SOUTH, PEDESTRIAN EAST WEST.
Cases to be handled:
• Handle the case if two pedestrians pushed the button together in two different traffics.
• Handle the case if the same button was being pressed more than one time during the same period of pedestrian crossing. (Period of pedestrian crossing is from when the button is pressed for the first time till the pedestrian traffic gets back to RED again.)
• Handle the case to delay the request of the pedestrian to cross if the button was pressed after 1 second from the end of the Period of pedestrian crossing.
