# Electronic Lock System
This electronic lock system, built using PIC microcontroller, can be used to protect any device with a password. Be it your ATM interaction, home/ office automation, industrial devices or even just your microcontroller based embedded project, you would not want a third person to access your device and be able to change the settings. In such cases, electronic lock system or electronic password protection system becomes handy. 

# Working of the lock system
The electronics circuit connection diagram is provided in the repository. The electronic lock takes input through a 4x3 keypad interfaced with a PIC18F458 microcontroller. The password entered by the user is stored in an array. After the user has entered a four digit password, that password is checked with a predefined password. If the password entered is correct, "Lock opened" message is displayed on the LCD screen. An incorrect password results in a message, "Wrong password". The interfacing of LCD is optional but it is a good way to track your status of password. Alternatively, an LED can also be used for indication. 

# Components used in the lock system
1. PIC18F458 controller
This is the brain of the entire project. It guides all the processes that include taking input through the keypad, displaying data on LCD and the checking task. A good knowledge of microcontrollers is needed to build this kind of system. 

2. Liquid Crystal Display
Popularly known as LCD, is the device used to know the status of the password system. It is used to display indication messages, "Enter password" when system is turned on, "Lock opened" when the password provided is true and "Wrong password" in other cases. It also displays the password you entered (although in a * form, for obvious reasons). 

3. 4x3 Keypad
This keypad is used to take input of password from the user. It consists of 12 push buttons with different labels. The microcontroller doesnot know about the labels and hence that needs to be explicitly coded. There are other types of keypads available and you can use any as per your needs.

# Software used
1. Proteus
This software was used to build the schematic diagram and run the simulation. The simulation can be done by giving the HEX file of the code to the microcontroller. 

2. MPLAB XC8
This is a compiler software that allows you to write code and generate their HEX files. 
Tip: Remember to turn off the Watch Dog Enable bit from the configuration bits in order to save your program from resetting frequently!

# Prequisites
The thorough theoretical knowledge of working of LCD and keypad is important for this application. Having learnt that, this project becomes a very easy task. 
