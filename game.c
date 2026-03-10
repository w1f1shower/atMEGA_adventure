#include "game.h"


int main(void) {

	lcd_init();
	adc_init();

	location_init(&lobby, tree);


	creature_init(&player);

	while (1) {
		uint8_t btn = read_button();
		player_control(&player, &lobby, btn);
	}
}
