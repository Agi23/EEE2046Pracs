#ifndef LCD_STM32F0_H
#define LCD_STM32F0_H
//********************************************************************
//*                      EEE2046F STM32F0                            *
//*                         LCD HEADER                               *
//*==================================================================*
//* WRITTEN BY:    R. Verrinder                                      *
//* MODIFIED:      03-08-2015                                        *
//*==================================================================*

#include "stm32f0xx.h"

//====================================================================
// GLOBAL CONSTANTS - LCD command codes
//====================================================================
#define    CLEAR           0x01
#define    CURSOR_HOME     0x02
#define    DISPLAY_ON      0x0C
#define    DISPLAY_OFF     0x08
#define    LINE_TWO        0xC0

#define    POWER_UP        0x33
#define    FOURBIT_MODE    0X32
#define    TWOLINE_MODE    0x28

#define    LCD_RS_SET      0b00000000000000000100000000000000
#define    LCD_RS_RESET    0b01000000000000000000000000000000
#define    LCD_EN_SET      0b00000000000000001000000000000000
#define    LCD_EN_RESET    0b10000000000000000000000000000000

#define    LCD_D4_SET      0b00000000000000000000000100000000
#define    LCD_D4_RESET    0b00000001000000000000000000000000
#define    LCD_D5_SET      0b00000000000000000000001000000000
#define    LCD_D5_RESET    0b00000010000000000000000000000000
#define    LCD_D6_SET      0b00000000000000000001000000000000
#define    LCD_D6_RESET    0b00010000000000000000000000000000
#define    LCD_D7_SET      0b00000000000000001000000000000000
#define    LCD_D7_RESET    0b10000000000000000000000000000000

#define    DELAY_COUNT     0x1FF

//====================================================================
// FUNCTION DECLARATIONS
//====================================================================
void init_LCD(void);

void lcd_command(unsigned char command);
void lcd_putchar(unsigned char character);
void lcd_putstring(char *instring);

void delay(unsigned int microseconds);
void pulse_strobe(void);

//====================================================================

#endif

//********************************************************************
// END OF PROGRAM
//********************************************************************
