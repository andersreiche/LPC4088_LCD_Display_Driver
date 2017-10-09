#include "board.h"
#include "lcd.h"


/*LCD data pins and ports*/
#define DATA_PORT0
#define DATA_PORT2
#define DATA_PORT3
#define DATA_PORT4
#define DATA_PORT5
#define DATA_PORT6
#define DATA_PORT7
#define DATA_PORT8
#define DATA_PIN1
#define DATA_PIN2
#define DATA_PIN3
#define DATA_PIN4
#define DATA_PIN5
#define DATA_PIN6
#define DATA_PIN7
#define DATA_PIN0

/*LCD command pins and ports*/
#define ENABLE_PORT
#define ENABLE_PIN
#define RS_PORT
#define RS_PIN
#define ENABLE_HIGH() Chip_GPIO_SetPinState(LPC_GPIO, ENABLE_PORT, ENABLE_PIN, 1);
#define ENABLE_LOW() Chip_GPIO_SetPinState(LPC_GPIO, ENABLE_PORT, ENABLE_PIN, 0);
#define RS_HIGH() Chip_GPIO_SetPinState(LPC_GPIO, RS_PORT, RS_PIN, 1);
#define RS_LOW() Chip_GPIO_SetPinState(LPC_GPIO, RS_PORT, RS_PIN, 0);

#define CMD_PORT3
#define CMD_PIN1
#define CMD_PIN2
#define CMD_PIN3

 // Chip_GPIO_SetPinState(LPC_GPIO, PORT, PIN, STATE(1,0));

void commandmode(void) {
	RS_LOW()
}

void datamode(void) {
	RS_HIGH()
}

void lcd_init(void) {
	// Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT0, DATA_PIN0, 1);
	// set R/W = W
}

void lcd_write() { // 8 bit databus


}


void lcd_set_cursor (int column, int row) {

}

void lcd_clear (void) {
	// clear = 00000001
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT0, DATA_PIN0, 1);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT1, DATA_PIN1, 0);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT2, DATA_PIN2, 0);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT3, DATA_PIN3, 0);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT4, DATA_PIN4, 0);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT5, DATA_PIN5, 0);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT6, DATA_PIN6, 0);
	Chip_GPIO_SetPinState(LPC_GPIO, DATA_PORT7, DATA_PIN7, 0);
}

void lcd_put_char(char c) {
	lcd_write_data(c);
}

void lcd_print(char *string) {
	while(*string) {
		lcd_put_char(*string++);
	}
}

void lcd_set_cursor_visibile(int visible) {
	lcd_write_cmd(0x0C | ((!!visible) << 1));
}

/* Very simple (inaccurate) delay function */
static void delay(uint32_t i)
{
	while (i--) {}
}

/* Delay in miliseconds  (cclk = 120MHz) */
static void delay_us(uint32_t ms)
{
	delay(ms * 40);
}
