#include "game.h"


int main(void) {

	lcd_init();
	adc_init();

	if (location_init(&lobby, tree) != 0)	engine_err(0xB7);
	if (creature_init(&player) 	!= 0)	engine_err(player.id);
	if (  object_init(&crate)	!= 0)	engine_err(crate.id);

	while (1) {
		uint8_t btn = read_button();
		player_control(&player, &lobby, btn);
		object_control(&crate, &player, &lobby);
	}
}
