#ifndef LCD_SCREEN_H
#define LCD_SCREEN_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// ==================================
// LCD Pins 
#define LCD_RS_PORT PORTB
#define LCD_RS_DDR  DDRB
#define LCD_RS_BIT  0    // D8

#define LCD_EN_PORT PORTB
#define LCD_EN_DDR  DDRB
#define LCD_EN_BIT  1    // D9

#define LCD_DATA_PORT PORTD
#define LCD_DATA_DDR  DDRD
#define LCD_DATA_MASK 0xF0 // D4-D7

// Backlight
#define LCD_BL_PORT PORTB
#define LCD_BL_DDR  DDRB
#define LCD_BL_BIT  2    // D10
// ==================================

#define LCD_RS_PORT PORTB
#define LCD_RS_DDR  DDRB
#define LCD_RS_BIT  0    // D8

#define LCD_EN_PORT PORTB
#define LCD_EN_DDR  DDRB
#define LCD_EN_BIT  1    // D9

// DATA pins - CRITICAL: Must be on the SAME PORT for reading
#define LCD_DATA_PORT PORTD
#define LCD_DATA_DDR  DDRD
#define LCD_DATA_PIN  PIND  // <-- THIS IS NEW: Input register
#define LCD_D4_BIT    4
#define LCD_D5_BIT    5
#define LCD_D6_BIT    6
#define LCD_D7_BIT    7
#define LCD_DATA_MASK 0xF0 // D4-D7 (bits 4-7)


void lcd_wait_busy(void);
void lcd_toggle_enable(void);
void lcd_write_nibble(uint8_t nibble, uint8_t is_data);
void lcd_command(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_init(void);
void lcd_goto(uint8_t row, uint8_t col);
void lcd_print(const char *str);
void lcd_clear(void);
void lcd_create_char(uint8_t slot, const uint8_t *bitmap);

#endif
