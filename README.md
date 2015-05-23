# Cochecito
Radio controlled car made for pure fun (and arduino-fu exercise)

MATERIALS:
- A 4xAA battery powered cheap remote controlled car toy (for chassis and drive motor/gearbox)
- A 7.4V LiPo battery from an old RC helicopter 
- Adafruit Pro Trinket (https://www.adafruit.com/product/2000)
- Generic PS2 wireless DualShock controller
- L298N based motor driver (search for "L298N" on eBay)
- A little servo (like this one: https://www.adafruit.com/products/169)
- 128x64 SSD1306 OLED Display (I2C). I bought a chinese one, but later I realized that since I'm using code from Adafruit, I should have bought one from them. https://www.adafruit.com/products/326

STEPS:
- Dissasemble the RC car and keep the chassis structure, suspension (if exists); wheels, motor, gearbox and so on. Receiver board, remote and plastic body/aileron can go now to the parts bin-
- Make space in the battery holder for the LiPo (dremel it until it fits)
- Remove the geared motor that drives the steering and replace it with the servo (dremel, metal pins, hot glue...)
- Connect the LiPo battery and the motor to the motor driver board. Secure it somewhere (hot glue, screws...). The driver board provides 5V for the trinket and its friends.
- Disassemble the DualShock receiver and make it breadboard-friendly. I glued a piece of perfboard and soldered wires from the PS2 connector to a pin strip. I've read online that it only works at 3.3V but mine works fine at 5V.
- Connect the Pro Trinket, the OLED, the receiver and the driver board together. The pins I used are on first section of Cochecito2.ino
- Uplolad sketch (all .ino files) to the Pro Trinket. It requires Adafruit SSD1306, Adafruit SfotServo, PS2X_lib and EEPROM.h libraries.

USING IT
- Y axis of the left stick controls the drive motor
- X axis of the right stick controls steering
- Keeping L2 pressed limits steering
- Keeping R2 pressed limits top speed
- Start enters in setup menu
    - Keypad up/down selects item
    - X = confirm
    - O = exit/cancel



