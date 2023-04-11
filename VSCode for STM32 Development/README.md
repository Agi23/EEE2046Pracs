# VSCode for STM32 Development
Prerequisite: VSCode installation + STM32 update and demo

## Get stm32-for-vscode extension
Navigate to the Extensions tab in VScode and install the stm32-for-vscode extension
<img width="552" alt="stm32Extension" src="https://user-images.githubusercontent.com/15980541/231163351-1b747808-ca5e-4e39-8222-affb2877c4e8.PNG">

**Note:** throughout this process, if you get a pop-up window in the bottom right corner asking you to install reccomended build tools - install them

## Download the template provided in this repository 
1. This template contains all the required files needed to start programming your STM32. 
2. In Core > Src there is a file called main.c - this is where you will be coding.
3. The code in the main.c file displays a "Hello World! :)" onto your LCD screen.

## Building and flashing your demo program
1. Once you have made changes to your code you will need to save everything and navigate to the STM32 tab in VSCode
<img width="227" alt="stm32Env" src="https://user-images.githubusercontent.com/15980541/231162914-8e7c5383-5801-4b5a-a456-ce18ea40541d.PNG">
2. Select "Build" to compile your code
3. After building, you can flash this code to your board by selecting "Flash STM32"
4. You should see "Hello World! :)" onto your LCD screen.


You are now ready to start programming your board with your own code :) 
