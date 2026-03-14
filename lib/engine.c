#include "../include/engine.h"
#include "../include/drivers.h"

void engine_err(uint8_t id) {
	lcd_command(0x80);
	char err_string[] = {'E', 'R', 'R', 'O', 'R', ':', id, 0};
	lcd_print(err_string);
	while(1){}
}

#include "engine/locations_engine.c"
#include "engine/creatures_engine.c"
#include "engine/player_engine.c"
