/*
 * garage.c
 *
 * Created: 24/02/2023 03:15:50 م
 * Author : ABdelrhman Ashraf
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD.h"
#include "HAL/LED/led.h"
#include "MCAL/TIMERS/timer.h"





int main(void)
{
	LED_vInit(PORT_C,1);
	LED_vInit(PORT_C,2);
	LED_vTurnOn(PORT_C,1);
	LCD_vInit();
	LCD_vSend_string("there are 0 cars");
	LCD_movecursor(2,1);
	LCD_vSend_string("garage is empty");
	uint8 flag1=0,flag2=0,IR1,IR2,counter=0;
	while(1)
	{
		IR1=DIO_u8read(PORT_D,0);
		if(IR1==1 && flag1==0 && counter<3)
		{
			counter++;
			LCD_movecursor(1,11);
			LCD_vSend_char(counter+48);
			flag1=1;
			if(counter==3)
			{
				LCD_clearscreen();
				LCD_vSend_string("there are 3 cars");
				LCD_movecursor(2,1);
				LCD_vSend_string("garage is full");
				LED_vTurnOn(PORT_C,2);
				LED_vTurnOff(PORT_C,1);
			}
			timer1_wave_fastPWM_B(-90);
			_delay_ms(1000);
			timer1_wave_fastPWM_B(0);
		}
		else if(IR1==0)
		{
			flag1=0;
		}
		
		IR2=DIO_u8read(PORT_D,1);
		if(IR2==1 && flag2==0 && counter>0)
		{
			counter--;
			LCD_movecursor(1,10);
			LCD_vSend_char(counter+48);
			flag2=1;
			
			LCD_clearscreen();
			LCD_vSend_string("there are ");
			LCD_vSend_char(counter+48);
			LCD_vSend_string(" cars");
			LCD_movecursor(2,1);
			LCD_vSend_string("garage has space");
			LED_vTurnOff(PORT_C,2);
			LED_vTurnOn(PORT_C,1);
			timer1_wave_fastPWM_A(-90);
			_delay_ms(1000);
			timer1_wave_fastPWM_A(0);
		}
		else if(IR2==0)
		{
			flag2=0;
		}
	}
}