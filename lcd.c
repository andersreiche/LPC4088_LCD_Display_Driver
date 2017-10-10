#include "board.h"
#include "lcd.h"


void setbus(char c) {
	/* set bits 0-7 according to char which can be passed as: "0bxxxxxxxx" or char*/
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT0, DATA_PIN0, c & 0b00000001);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT1, DATA_PIN1, c & 0b00000010);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT2, DATA_PIN2, c & 0b00000100);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT3, DATA_PIN3, c & 0b00001000);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT4, DATA_PIN4, c & 0b00010000);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT5, DATA_PIN5, c & 0b00100000);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT6, DATA_PIN6, c & 0b01000000);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT7, DATA_PIN7, c & 0b10000000);
}

void commandmode(void) {
	RS_LOW()
}

void datamode(void) {
	RS_HIGH()
}

void lcd_init(void) {
	RW_W() // sets the display to write mode, this will never change
	lcd_write_cmd(LCD_FORMAT);
	lcd_write_cmd(LCD_CLEAR);

}

void lcd_write_data(char c) {
	datamode();
	ENABLE_READY()
	setbus(c);
	delay_us(10);
	ENABLE_SEND()
}

void lcd_write_cmd(char c) {
	commandmode();
	ENABLE_READY()
	setbus(c);
	delay_us(10);
	ENABLE_SEND()
}

void lcd_put_char(char c) {
	lcd_write_data(c);
}

void lcd_print(char *string) {
	while (*string) {
		lcd_put_char(*string++);
	}
}

/* Very simple (inaccurate) delay function */
static void delay(uint32_t i) {
	while (i--) {
	}
}

/* Delay in mucroseconds  (cclk = 120MHz) */
static void delay_us(uint32_t ms) {
	delay(ms * 40);
}
