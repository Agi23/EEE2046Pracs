# EEE2046Pracs

## Windows C Setup
This tutorial is based on the video: https://youtu.be/oaebkkOP2Qg

### Download and extract MinGW
1. Download MinGW: https://nuwen.net/files/mingw/mingw-18.0-without-git.exe
2. Once downloaded, you should see a file like below. Double click on the icon and set the extraction location to C:\
<img width="789" alt="mingwExtraction" src="https://user-images.githubusercontent.com/15980541/228197825-61c7aac9-1e05-4845-afdc-9e07c4948141.PNG">

### Add Environment Variable
1. Click on the Start menu and search for "Environment Variables".
2. Click on "Edit the system environment variables".
3. Click on the "Environment Variables" button.
<img width="307" alt="environmentvar" src="https://user-images.githubusercontent.com/15980541/228201535-a165e17b-9b05-4961-b626-07f863a0fc21.PNG">

4. Under "System Variables", find the "Path" variable and click "Edit".
<img width="441" alt="envVarEdit" src="https://user-images.githubusercontent.com/15980541/228201591-b904b791-6275-4cd5-b7f7-29836e6da9c3.PNG">

5. Click "New" and add the following path: "C:\MinGW\bin". Make sure to replace "C:\MinGW" with the installation directory you chose during the MinGW installation.
<img width="376" alt="envVarNew" src="https://user-images.githubusercontent.com/15980541/228201641-a1b5721c-db47-4e65-9625-e252f7558745.PNG">

6. Click "OK" on all open windows to save the changes.

### Check installation 
1. Open the Command Prompt by clicking on the Start menu and searching for "Command Prompt"
2. Run the following command
gcc --version
3. You should see something like this:
<img width="435" alt="gccVersion" src="https://user-images.githubusercontent.com/15980541/228206129-94ef09df-2c4a-4442-8f3c-c5eb86b022e7.PNG">

## macOS C Setup
1. Open Terminal by clicking on the magnifying glass icon in the top right corner of the screen and typing "Terminal" in the search bar.
2. In the Terminal window, type the following command:
```
xcode-select --install
```
3. You will be prompted to install the Command Line Tools. Click "Install" and follow the prompts to complete the installation.

## Visual Studio Code Download
1. Navigate to https://code.visualstudio.com/download
2. Download the relevant OS
3. Proceed with installation 

### Extensions
You will need to install the following extensions:

<img width="230" alt="cExtension" src="https://user-images.githubusercontent.com/15980541/228511715-be3d3d37-8aaa-47f2-94d3-fef9f2dd9b9b.PNG">

1. Click on the Extensions icon on the left-hand side of the VSCode window (it looks like a square with four squares inside it).
2. In the search bar at the top of the Extensions panel, type "C/C++" and press Enter.
3. Click on the "C/C++" extension from Microsoft.
4. Click the green "Install" button.

## Creating and running your first C program
1. Create a new file called `hello.c` with the following code
```
#include <stdio.h>

int main() {
   printf("Hello, world!");
   return 0;
}
```
2. Open the terminal in VSCode and run the following command to compile the c code
```
gcc hello.c -o hello
```
3. An exe called `hello.exe` should now be in your folder. Run the exe file using the following commad:
```
./hello
```
4. Your output should be as follows:
<img width="473" alt="VScodeTerminalC" src="https://user-images.githubusercontent.com/15980541/228214933-07913e79-d6a1-4200-9279-f1494ff2860c.PNG">

## C-programming with the STM32

TODO
