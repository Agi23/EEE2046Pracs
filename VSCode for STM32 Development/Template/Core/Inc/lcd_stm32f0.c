//********************************************************************
//*                      EEE2046F STM32F0                            *
//*                         LCD MODULE                               *
//*==================================================================*
//* WRITTEN BY:    Copyright (C) Samuel Ginsberg 2004                *
//* PORTED TO STM32F0 dev board by James Gowans, 2014                *
//* MODIFIED BY:   Robyn Verrinder                                   *
//* DATE CREATED:  2004                                              *
//* PORTED:	   2014						     *
//* MODIFIED:      03-08-2015                                        *
//*==================================================================*
//* PROGRAMMED IN: ECLIPSE IDE Luna Service Release 1 (4.4.1)        *
//* DEV. BOARD:    UCT STM32 Development Board                       *
//* TARGET:	   STMicroelectronics STM32F051C6                    *
//*==================================================================*
//* DESCRIPTION:   This code contains common functions to communicate*
//*                with the LCD module connected to the STM32 uC.    *
//*==================================================================*
//* LCD SETUP:     - 4 bit mode      (Upper 4 data lines D4-D7 used) *
//*                - Two lines used                                  *
//*                - Flashing cursor                                 *
//*==================================================================*
//* CONNECTIONS:                                                     *
//*------------------------------------------------------------------*
//* LCD PINS   | NAME                    | CONNECTED TO              *
//*------------------------------------------------------------------*
//* 1............VSS.......................GND                       *
//* 2............VDD.......................+5V                       *
//* 3............CONTRAST..................POT 2                     *
//* 4............RS  - Register Select.....PC14 (LCD_RS)             *
//* 5............RW  - Read/Write..........GND                       *
//* 6............E   - Enable..............PC15 (LCD_E)              *
//* 7............D0  - Data line 0.........GND                       *
//* 8............D1  - Data line 1.........GND                       *
//* 9............D2  - Data line 2.........GND                       *
//* 10...........D3  - Data line 3.........GND                       *
//* 11...........D4  - Data line 4.........PB8  (LCD_D4)             *
//* 12...........D5  - Data line 5.........PB9  (LCD_D5)             *
//* 13...........D6  - Data line 6.........PA12 (LCD_D6)             *
//* 14...........D7  - Data line 7.........PA15 (LCD_D7)             *
//* 15...........CATHLED...................NC                        *
//* 16...........ANODELED..................NC                        *
//********************************************************************
// INCLUDE FILES
//====================================================================
#include "lcd_stm32f0.h"
#include "stm32f0xx.h"
//====================================================================
// SEND COMMAND CODE TO LCD - LCD_Command(command)
//====================================================================
// DESCRIPTION: This function sends a command to the LCD. Care is taken
//              not to interfere with the other lines on the port.
//
//              As we are using a microcontroller to control the LCD
//              we use 4-bit mode to save on number of lines used to
//              connect to the LCD. This means that an 8-bit command
//              must be split into two sets of 4-bits (upper and lower)
//              These sets must be transmitted
//====================================================================
// USEFUL COMMANDS:
//                  - POWER_UP:      Power up initialization for the lcd
//                  - FOURBIT_MODE:  Sets LCD for 4-bit mode
//                  - TWOLINE_MODE:  Sets up 2 lines and character size
//                  - SETUP_CURSOR:  Turn display on and set up cursor
//                  - CLEAR:         Clear screen
//                  - CURSOR_HOME:   Cursor home
//                  - LINE_TWO:      Line 2
//
//====================================================================

void lcd_command(unsigned char command)
{
    GPIOC->BSRR |= LCD_RS_RESET;	// Register Select (RS)line low (data sent will now be read as commands);

// Put upper nibble (upper 4-bits) on data lines, command mode
// DATALINE 7
    if ((command & 0x80) != 0)		// Select bit 7 of command, if HIGH set Data line 7 (D7) 
    {
    	GPIOA->BSRR |= LCD_D7_SET;
    }
    else				// else RESET D7
    {
    	GPIOA->BSRR |= LCD_D7_RESET;
    }
// DATALINE 6
    if ((command & 0x40) != 0)		// Select bit 6 of command, if HIGH set Data line 6 (D6) 
    {
        GPIOA->BSRR |= LCD_D6_SET;
    }
    else				// else RESET D6
    {
        GPIOA->BSRR |= LCD_D6_RESET;
    }
// DATALINE 5
    if ((command & 0x20) != 0)		// Select bit 5 of command, if HIGH set Data line 5 (D5)
    {
    	GPIOB->BSRR |= LCD_D5_SET;	
    }
    else				// else RESET D5
    {
    	GPIOB->BSRR |= LCD_D5_RESET;
    }
// DATALINE 4
    if ((command & 0x10) != 0)		// Select bit 4 of command, if HIGH set Data line 4 (D4)
    {
    	GPIOB->BSRR |= LCD_D4_SET;
    }
    else				//  else RESET D4
    {
    	GPIOB->BSRR |= LCD_D4_RESET;
    }

    pulse_strobe ();			// Send data

// lower nibble to data lines
    if ((command & 0x08) != 0)		// Select bit 3 of command, if HIGH set Data line 7 (D7) 
    {
    	GPIOA->BSRR |= LCD_D7_SET;
    }
    else				// else RESET D7
    {
    	GPIOA->BSRR |= LCD_D7_RESET;
    }
// DATALINE 6
    if ((command & 0x04) != 0)		// Select bit 2 of command, if HIGH set Data line 6 (D6)
    {
        GPIOA->BSRR |= LCD_D6_SET;
    }
    else				//  else RESET D6
    {
        GPIOA->BSRR |= LCD_D6_RESET;
    }
    // DATALINE 5
    if ((command & 0x02) != 0)		// Select bit 1 of command, if HIGH set Data line 5 (D5)
    {
    	GPIOB->BSRR |= LCD_D5_SET;         
    }
    else				//  else RESET D5
    {
    	GPIOB->BSRR |= LCD_D5_RESET;
    }
    // DATALINE 4
    if ((command & 0x01) != 0)		// Select bit 0 of command, if HIGH set Data line 4 (D4)
    {
    	GPIOB->BSRR |= LCD_D4_SET;
    }
    else				//  else RESET D4
    {
    	GPIOB->BSRR |= LCD_D4_RESET;
    }

    pulse_strobe();			// Send data
    delay(3000);
}

//====================================================================
// INITIALISE LCD - LCD_Init()
//====================================================================
// DESCRIPTION: This function sets up the port lines for the LCD and
//              intialises the module for use.
//====================================================================
// LCD SETUP:     - 4 bit mode      (Upper 4 data lines D4-D7 used)
//                - Two lines used
//                - Flashing cursor
//====================================================================

void init_LCD(void)
{
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;	// Connect clocks to GPIO A, B and C
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;

    GPIOA->MODER |= (GPIO_MODER_MODER12_0|GPIO_MODER_MODER15_0); // D6 and D7
    GPIOB->MODER |= (GPIO_MODER_MODER8_0|GPIO_MODER_MODER9_0);   // D4 and D5
    GPIOC->MODER |= (GPIO_MODER_MODER14_0|GPIO_MODER_MODER15_0); // RS and EN

    delay(30000);			// Allow the LCD some power up time (~30ms)

    lcd_command(POWER_UP);		// Power up initialization for the lcd
    lcd_command(FOURBIT_MODE);		// Set LCD into 4 bit mode
    lcd_command(DISPLAY_ON);		// Turn display on and set up cursor
    lcd_command(TWOLINE_MODE);		// Set up 2 lines and character size
    lcd_command(CLEAR);			// Clear display
}

//====================================================================
// WRITE A SINGLE CHARACTER TO THE LCD - LCD_PutChar(character)
//====================================================================
// DESCRIPTION: Puts a single character on the LCD at the next position
//              on the screen. The character to be printed is in the input
//              parameter. For numbers, letters and other common characters
//              the ASCII code will produce correct display.
//
//              Refer to the Hitachi HD44780 datasheet for full character
//              set information.
//====================================================================

 void lcd_putchar(unsigned char character)
{
	GPIOC->BSRR |= LCD_RS_SET;	// Register Select (RS) line HIGH (data sent will now be read as text);
// Put upper nibble (upper 4-bits) on data lines, command mode
// DATALINE 7
        if ((character & 0x80) != 0) 	// Select bit 7 of command, if HIGH set Data line 7 (D7)
        {
        	GPIOA->BSRR |= LCD_D7_SET;
        }
        else				//  else RESET D7
        {
        	GPIOA->BSRR |= LCD_D7_RESET;
        }
        // DATALINE 6
        if ((character & 0x40) != 0)	// Select bit 6 of command, if HIGH set Data line 6 (D6)       
	{
            GPIOA->BSRR |= LCD_D6_SET;
        }
        else				//  else RESET D6

        {
            GPIOA->BSRR |= LCD_D6_RESET;
        }
// DATALINE 5
        if ((character & 0x20) != 0)	// Select bit 5 of command, if HIGH set Data line 5 (D5)

        {
        	GPIOB->BSRR |= LCD_D5_SET;                 
	}
        else				//  else RESET D5
        {
        	GPIOB->BSRR |= LCD_D5_RESET;
        }
// DATALINE 4
        if ((character & 0x10) != 0)	// Select bit 4 of command, if HIGH set Data line 4 (D4) 
        {
        	GPIOB->BSRR |= LCD_D4_SET;
        }
        else				// else RESET D4
        {
        	GPIOB->BSRR |= LCD_D4_RESET;
        }

        pulse_strobe ();		// Send data

// lower nibble to data lines
        if ((character & 0x08) != 0)	// Select bit 3 of command, if HIGH set Data line 7 (D7) 
        {
        	GPIOA->BSRR |= LCD_D7_SET;
        }
        else				// else RESET D7
        {
        	GPIOA->BSRR |= LCD_D7_RESET;
        }
// DATALINE 6
        if ((character & 0x04) != 0)	// Select bit 2 of command, if HIGH set Data line 6 (D6)         
	{
            GPIOA->BSRR |= LCD_D6_SET;
        }
        else				// else RESET D6

        {
            GPIOA->BSRR |= LCD_D6_RESET;
        }
// DATALINE 5
        if ((character & 0x02) != 0)	// Select bit 1 of command, if HIGH set Data line 5 (D5)  
        {
        	GPIOB->BSRR |= LCD_D5_SET;       
	}
        else				// else RESET D5
        {
        	GPIOB->BSRR |= LCD_D5_RESET;
        }
// DATALINE 4
        if ((character & 0x01) != 0)	// Select bit 0 of command, if HIGH set Data line 4 (D4)
        {
        	GPIOB->BSRR |= LCD_D4_SET;
        }
        else				//  else RESET D4
        {
        	GPIOB->BSRR |= LCD_D4_RESET;
        }

        pulse_strobe();			// Send data
}

//====================================================================
// WRITE A STRING TO THE LCD - LCD_PutString(ptr_String)
//====================================================================
// DESCRIPTION: Writes a string to the LCD
//====================================================================

void lcd_putstring(char *instring)
{
    unsigned char count = 0;

    while (instring[count])		// Until the null terminator is reached
    {
    	lcd_putchar(instring[count]);	// Write each character to LCD
	    count++;
	 }
}


//====================================================================
// PULSE STROBE - Pulse_Strobe()
//====================================================================
// DESCRIPTION: Pulse the strobe line of the LCD to indicate that data is ready.
//====================================================================

void pulse_strobe(void)
{
    delay(20);				// Delay

    GPIOC->BSRR |= LCD_EN_SET;		// pull E (PC15) HIGH

    delay(20);				// Delay

    GPIOC->BSRR |= LCD_EN_RESET;	// Take EN LOW

    delay(20);				// Delay

    GPIOC->BSRR |= LCD_EN_SET;		// Take EN HIGH
}


//====================================================================
// LOOP DELAY - delay(microseconds)
//====================================================================
// DESCRIPTION: A delay used by the LCD functions.
//====================================================================

void delay(unsigned int microseconds)
{
	  volatile unsigned int counter;
	  microseconds *= 3;
	  for(counter = 0; counter<microseconds; counter++)
	  {
	    __asm("nop");
	    __asm("nop");
	  }
}

//********************************************************************
// END OF PROGRAM
//********************************************************************


