# EEE2046Pracs

## Windows C-programming
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


## Visual Studio Code Download
1. Navigate to https://code.visualstudio.com/download
2. Download the relevant OS
3. Proceed with installation 


### Extensions
You will need the following extensions:

### Creating your first C program
