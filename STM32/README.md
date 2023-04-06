# STM32 hardware and soldering
## Follow the [YouTube tutorial](https://youtu.be/DUCspVEbiYw)
Note: there is a mistake in the video. It mentions a 1.6kΩ resistor, but this is meant to be a **1.8kΩ** resistor.

### Connecting jumpers
Connect your jumpers as shown marked in blue
![jumpers](https://user-images.githubusercontent.com/15980541/230367093-1b24aa17-a295-4b20-8b77-5fc1efe39b9a.PNG)

### Detachable component soldering
The next step is to solder your detachable parts: ST-LINK, LCD and STM32 chip all shown in red.
![detach](https://user-images.githubusercontent.com/15980541/230367127-c0427905-5d35-4f0e-b3b9-1506c13c9093.PNG)

These parts fit into the female headers you soldered in the tutorial. Solder male headers to these individual parts so they are able to fit into the female sockets on the board. Remember to solder the headers with the long end facing down so a good connection to the female headers can occur.

Here is an example with the LCD:
![LCD](https://user-images.githubusercontent.com/15980541/230368539-ec6fc63f-e2ec-4f18-a54f-69e03078ab17.jpg)

# Testing

## Test 1
1. Remove all your detachable components as well as the EEPROM chip 
2. Plug your USB cable into the port on the left side of the board powered by a laptop/pc port
3. The green light on the bottom left side of the board should be illuminated, if not then there is a problem and this needs to be rectified before moving onto the next step.
## Test 2
1. Plug in all your components into the board
2. Plug your USB cable into the port on the left side of the board powered by a laptop/pc USB port
3. Your LCD screen should be illuminated and a series of dark squares should be seen on the display. If the screen is illuminated but can't see the squares, adjust the potentiometer on the board with a screw driver to adjust the contrast.

# Loading a demo program onto your development board 
Now you have a working board, you can move onto updating the firmware and downloading a test program
## Upgrade the ST-LINK
Note: this method only works for Windows. 
1. Connect your board to your laptop using the USB cable
2. Download the folder "ST-LinkUpgrade" and run the executable file ST-LinkUpgrade.exe
3. Click on the button "Device Connect" and then select "Yes" to upgrade

## Test program
1. Download STM32CubeProgrammer here (https://www.st.com/en/development-tools/stm32cubeprog.html) and run the program
2. Connect your board to your laptop using the USB cable
3. Click on the green "Connect" button in the top right corner to connect to the device (you may need to upgrade the firmware)
4. Click on "Open file" and select demo_2015.elf
5. Click download and the demo program should be flashed to your board
