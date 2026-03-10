#ifndef ADC_BUTTTONS_H
#define ADC_BUTTTONS_H

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// Button Thresholds (Calibrate these if needed!)
#define BTN_RIGHT_MAX  50
#define BTN_UP_MAX     200
#define BTN_DOWN_MAX   400
#define BTN_LEFT_MAX   600
#define BTN_SELECT_MAX 800

enum { 
	BTN_NONE = 0, 
	BTN_RIGHT, 
	BTN_UP, 
	BTN_DOWN, 
	BTN_LEFT, 
	BTN_SELECT 
};


void adc_init(void);
uint16_t adc_read(void);
uint8_t read_button(void);

#endif
