/*
 * LCD.h
 *
 * Created: 2/23/2022 4:36:45 PM
 *  Author: sharasa
 */ 

#ifndef LCD_H_
#define LCD_H_
#define EN 0
#define RS 1
#define RW 2
#include "../../MCAL/DIO/DIO.h"
#include "LCD_config.h"

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#if defined four_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38




#endif /* LCD_H_ */

/*
	Function Name        : LCD_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initialize the LCD screen to be ready for use.
*/
void LCD_vInit(void);

/*
	Function Name        : LCD_vSend_cmd
	Function Returns     : void
	Function Arguments   : uint8 cmd
	Function Description : Send the given command to be executed by the LCD.
*/
void LCD_vSend_cmd(uint8 cmd);

/*
	Function Name        : LCD_vSend_char
	Function Returns     : void
	Function Arguments   : uint8 data
	Function Description : Print the given character on the LCD screen at the current cursor location.
*/
void LCD_vSend_char(uint8 data);

/*
	Function Name        : LCD_vSend_string
	Function Returns     : void
	Function Arguments   : char *data
	Function Description : Print the given string at the current cursor location.
*/
void LCD_vSend_string(char *data);

/*
	Function Name        : LCD_clearscreen
	Function Returns     : void
	Function Arguments   : void
	Function Description : Clear all printed characters and move the cursor to the first location at the first line
*/
void LCD_clearscreen(void);

/*
	Function Name        : LCD_movecursor
	Function Returns     : void
	Function Arguments   : uint8 row ,uint8 column
	Function Description : Move the cursor at the given row and column (Rows 1:2 , Cols 1:16)
*/
void LCD_movecursor(uint8 row,uint8 column);

#endif /* LCD_H_ */