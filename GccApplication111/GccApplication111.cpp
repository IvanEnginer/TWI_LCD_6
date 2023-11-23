#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "TWI.h"
#include "LCD_I2C.h"

int n=1;

char unit[][32] =
{
	"Unit 1",
	"Unit 2",
	"Unit 3",
	"Unit 4",
	"Unit 5",
	"Unit 6",
	"Unit 7",
	"Unit 8",
	"Unit 9",
	"Unit 10",
	"Unit 11",
	"Unit 12",
	"Unit 13",
	"Unit 14",
	"Unit 15"	
};

int main(void)
{
	I2C_Init();
	lcd_init();
	lcd_clear();
	lcd_putstring(unit[0]);
	lcd_gotoxy(0,1);
	lcd_putstring(unit[1]);
    while(1)
    {
        lcd_clear();
		lcd_putstring(unit[n++]);	
		_delay_ms(100);
		lcd_gotoxy(0,1);
		lcd_putstring(unit[n++]);
		_delay_ms(1000);
		if (n==15)
		{
			n=13;
		}
				
    }
}