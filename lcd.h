/*!
 * \file      lcd.h
 * \brief     Driver for Hitachi HD44780 LCD controller in 4-bit mode.
 * \copyright ARM University Program &copy; ARM Ltd 2014.
 */
#ifndef LCD_H
#define LCD_H

#define LCD_CLEAR 0b00000001
#define LCD_FORMAT 0b00111100
/*! \brief Initialises the LCD module.
 */
void lcd_init(void);


/*! \brief Prints the null terminated string to the LCD and
 *         increments the cursor.
 *  \param string  Null terminated string to be printed.
 */
void lcd_print(char *string);

/*! \brief Prints the specified character to the LCD and
 *         increments the cursor.
 *  \param c  Character to be printed.
 */
void lcd_put_char(char c);

/*! \brief Enables or disables visibility of the cursor.
 *  \param visible New visibility of the cursor.
 */

void lcd_write_data(char c);
void lcd_write_cmd(char c);
void displaymode8bit2lines();
void commandmode(void);
void datamode(void);

static void delay(uint32_t i);
static void delay_us(uint32_t ms);

#endif // LDC_H
