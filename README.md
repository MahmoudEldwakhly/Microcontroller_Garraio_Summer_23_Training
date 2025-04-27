# Microcontroller Garraio Summer 2023 Training (Tiva C Board)

During the Summer of 2023, I took part in the **Microcontroller Garraio Training** — an amazing introduction to the world of embedded systems using the **Tiva C microcontroller** from Texas Instruments.  
Throughout the training, I worked on many projects, learned how to read datasheets, and gained hands-on experience in real embedded applications.

## Course Highlights

- **Register/API Level Programming:**  
  Learned how to control hardware directly using register-level programming, and how to use APIs to make working with peripherals easier and more organized.

- **Driver Libraries (TivaWare):**  
  Explored how to use the TivaWare driver library to simplify complex hardware programming and to build more reliable and readable code.

- **GPIO (General Purpose Input/Output):**  
  Practiced using GPIO pins by controlling LEDs, reading input from buttons, and interacting with external devices like potentiometers.

- **SysTick Timer:**  
  Used the SysTick timer to create accurate time delays and to manage simple scheduling tasks within the system.

- **GPTM (General-Purpose Timer Module):**  
  Worked with general timers to measure time intervals, create delays, and synchronize tasks inside the microcontroller.

- **I2C Communication:**  
  Learned how to connect microcontrollers with other devices using the I2C protocol, mastering both master and slave communication.

- **ADC (Analog-to-Digital Converter):**  
  Learned how to read analog signals, like from a potentiometer, and convert them into digital values that the microcontroller could use.

- **UART (Serial Communication):**  
  Implemented UART communication to send and receive data between the microcontroller and external devices, helping to monitor the system easily.

- **EEPROM (Non-Volatile Memory):**  
  Explored how to save and retrieve important data even after power loss by using EEPROM.

- **DMA (Direct Memory Access):**  
  Used DMA to move data efficiently without burdening the CPU, improving overall system performance.

## Outcome

For each topic, I built a small project to apply it practically. At the end of the course, I combined everything I learned into a **final integrated project**.

---

# Projects Completed

1. **Button-Controlled LED:**  
   When any Tiva C board button is pressed, a white LED turns on.

2. **Blinking LED with Different Intervals:**  
   Blinking an LED every 0.5, 1, 2.5, and 10 seconds using the SysTick timer, regular timers, and interrupts.

3. **Keypad Calculator:**  
   Connected a keypad and made a simple calculator that uses interrupts and UART to show results.

4. **ADC Potentiometer Project:**  
   Used a potentiometer to control the ON/OFF status of an LED and printed the changing values through UART communication.

5. **I2C Between Two Tiva Boards:**  
   Set up two Tiva C boards where pressing a button on one board toggles an LED on the other board using I2C communication.

6. **UDMA and EEPROM Project:**  
   Practiced reading and writing data using DMA and stored critical data into EEPROM.

7. **Final Project: Smart Traffic Light Controller**

   ### Project Overview

   - **Car Traffic Lights:**  
     Programmed two car traffic lights (north-south and east-west) to follow a sequence:  
     - GREEN for 5 seconds  
     - YELLOW for 2 seconds  
     - RED for a short 1-second delay before switching to the other light

   - **Pedestrian Traffic Lights:**  
     Added two pedestrian buttons. When a pedestrian presses the button, the car traffic light that’s green will pause, and the pedestrian’s light will turn green for 2 seconds to allow safe crossing. After crossing, the car light resumes from where it was interrupted.

   - **UART Status Reporting:**  
     Every time the system state changes (for cars or pedestrians), a message is sent via UART to show what’s happening — for example, "Cars North-South Green" or "Pedestrian East-West Crossing".

   ### Special Cases Handled

   - If two pedestrians press the buttons at the same time, the system manages the crossings without conflict.
   - If a pedestrian presses the button multiple times during an active crossing, the system ignores repeated requests.
   - If a pedestrian presses the button too late (after the crossing period ends), the system queues the request until it’s safe to allow crossing again.
