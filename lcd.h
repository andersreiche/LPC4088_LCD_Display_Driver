/*!
 * \file      lcd.h
 * \brief     Driver for Hitachi HD44780 LCD controller in 4-bit mode.
 * \copyright ARM University Program &copy; ARM Ltd 2014.
 */
#ifndef LCD_H
#define LCD_H

/* macros for the display */
#define LCD_CLEAR 0b00000001
#define LCD_FORMAT 0b00111100

/*LCD data pins and ports*/
#define DATA_PORT0 0
#define DATA_PORT1 0
#define DATA_PORT2 0
#define DATA_PORT3 0
#define DATA_PORT4 0
#define DATA_PORT5 0
#define DATA_PORT6 0
#define DATA_PORT7 0
#define DATA_PIN0 21	//bit 0 LSB
#define DATA_PIN1 0		//bit 1
#define DATA_PIN2 1		//bit 2
#define DATA_PIN3 9		//bit 3
#define DATA_PIN4 8		//bit 4
#define DATA_PIN5 7		//bit 5
#define DATA_PIN6 6		//bit 6
#define DATA_PIN7 23	//bit 7 MSB

/*LCD command pins and ports*/
#define ENABLE_PORT 0
#define RS_PORT 0
#define RW_PORT 0
#define ENABLE_PIN 24	//Enable
#define RS_PIN 25		//Register Select
#define RW_PIN 26		//Read/Write

/* macros for setting common pin states */
#define ENABLE_READY() Chip_GPIO_SetPinState(LPC_GPIO, ENABLE_PORT, ENABLE_PIN, 1);
#define ENABLE_SEND() Chip_GPIO_SetPinState(LPC_GPIO, ENABLE_PORT, ENABLE_PIN, 0);
#define RS_HIGH() Chip_GPIO_SetPinState(LPC_GPIO, RS_PORT, RS_PIN, 1);
#define RS_LOW() Chip_GPIO_SetPinState(LPC_GPIO, RS_PORT, RS_PIN, 0);
#define RW_W() Chip_GPIO_SetPinState(LPC_GPIO, RW_PORT, RW_PIN, 0);
#define RW_R() Chip_GPIO_SetPinState(LPC_GPIO, RW_PORT, RW_PIN, 1);


void lcd_init(void);			// init
void lcd_print(char *string);	// prints string to display
void lcd_put_char(char c);		// prints char to display
void lcd_write_data(char c);	// write ASCI characters on the databus
void lcd_write_cmd(char c);		// write commands on the databus
void displaymode8bit2lines();	// sets up display to 8bit data with 2 lines
void commandmode(void);			// sets the register select to 0
void datamode(void);			// sets the register select to 1

static void delay(uint32_t i);		// delay function
static void delay_us(uint32_t ms);	// implementation of delay function in µs

#endif // LDC_H
