#include "../../include/drivers/adc_buttons.h"

void adc_init(void) {
	ADMUX  = (1 << REFS0); 	/*| AVCC Reference |*/
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); /*| Enable ADC, Prescaler 128, Auto Trigger Disable, Interrupt Disable |*/ 
}

uint16_t adc_read(void) {
	ADCSRA |= (1 << ADSC);		/*| Start |*/
	while (ADCSRA & (1 << ADSC));	/*| Wait  |*/
	return ADC;
}

uint8_t read_button(void) {
	uint16_t val = adc_read();
	if (val < BTN_RIGHT_MAX)   return BTN_RIGHT;
	if (val < BTN_UP_MAX)      return BTN_UP;
	if (val < BTN_DOWN_MAX)    return BTN_DOWN;
	if (val < BTN_LEFT_MAX)    return BTN_LEFT;
	if (val < BTN_SELECT_MAX)  return BTN_SELECT;

	return BTN_NONE;
}

