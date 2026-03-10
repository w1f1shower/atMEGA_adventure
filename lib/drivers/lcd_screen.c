#include "../../include/drivers/lcd_screen.h"
#include <string.h>
#include <stdlib.h>


void lcd_toggle_enable(void) {
	LCD_EN_PORT |= (1 << LCD_EN_BIT);
	_delay_us(5);
	LCD_EN_PORT &= ~(1 << LCD_EN_BIT);
	_delay_us(5);
}

void lcd_write_nibble(uint8_t nibble, uint8_t is_data) {
	LCD_DATA_PORT = (LCD_DATA_PORT & ~LCD_DATA_MASK) | ((nibble & 0x0F) << 4);
	if (is_data)	LCD_RS_PORT |=  (1 << LCD_RS_BIT);
	else		LCD_RS_PORT &= ~(1 << LCD_RS_BIT);
	lcd_toggle_enable();
}

void lcd_command(uint8_t cmd) {
	lcd_write_nibble(cmd >> 4, 0);
	lcd_write_nibble(cmd & 0x0F, 0);
	_delay_us(50);
}

void lcd_data(uint8_t data) {
	lcd_write_nibble(data >> 4, 1);
	lcd_write_nibble(data & 0x0F, 1);
	_delay_us(50);
}

void lcd_init(void) {
	LCD_RS_DDR |= (1 << LCD_RS_BIT);
	LCD_EN_DDR |= (1 << LCD_EN_BIT);
	LCD_DATA_DDR |= LCD_DATA_MASK;
	LCD_BL_DDR |= (1 << LCD_BL_BIT);
	LCD_BL_PORT |= (1 << LCD_BL_BIT); /*| Turn Backlight ON |*/

	_delay_ms(50);
	lcd_write_nibble(0x03, 0); _delay_ms(5);
	lcd_write_nibble(0x03, 0); _delay_ms(5);
	lcd_write_nibble(0x03, 0); _delay_ms(5);
	lcd_write_nibble(0x02, 0); 		/*| 4-bit mode |*/

	lcd_command(0x28); /*| Function Set	|*/
	lcd_command(0x0C); /*| Display On	|*/
	lcd_command(0x06); /*| Entry Mode 	|*/
	lcd_command(0x01); /*| Clear		|*/
	_delay_ms(2);
	//return 0;
}

void lcd_goto(uint8_t row, uint8_t col) {
	lcd_command((row == 0 ? 0x80 : 0xC0) + col);
}

void lcd_print(const char *str) {
	while (*str) lcd_data(*str++);
}

void lcd_clear(void) {
	lcd_command(0x01);
	_delay_ms(2);
}

/*| Creating a custom character (CG RAM) |*/
void lcd_create_char(uint8_t slot, const uint8_t *bitmap) {
	lcd_command(0x40 | (slot << 3)); /*| Set CG RAM address |*/

	for (uint8_t i = 0; i < 8; i++) {
		lcd_data(bitmap[i]);
	}

	lcd_command(0x80); /*| Return to DD RAM |*/
}
