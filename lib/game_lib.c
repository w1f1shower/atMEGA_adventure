#include "../include/game_lib.h"
#include "../include/drivers/lcd_screen.h"
#include "../include/drivers/adc_buttons.h"


void creature_init(struct creature *creature) {
	lcd_create_char(creature->id, creature->sides[creature->direction]);

	creature->position.x = 8;
	creature->position.y = 1;

	creature->prev_position.x = creature->position.x;
	creature->prev_position.y = creature->position.y;

	lcd_goto(creature->position.y, creature->position.x);
}

void location_init(struct location *location, uint8_t uniq_chars[][8]) {
	lcd_command(0x80);
	for (uint8_t uniq = 0, id = LOCATION_FRAME_ID1; id <= LOCATION_FRAME_ID4; uniq++, id++) {
		lcd_create_char(id, uniq_chars[uniq]);
	}
	
	for (uint8_t row = 0; row < 2; row++) {
		for (uint8_t col = 0; col < 16; col++) {
			lcd_data(location->field[row][col]);
				if (col == 15) lcd_command(0xC0);
		}
	}
}

void player_control(struct creature *player, struct location *location, uint8_t btn) {
	if (btn != BTN_NONE ) {
		player->prev_position.x = player->position.x;
		player->prev_position.y = player->position.y;
	
		if (btn == BTN_LEFT && player->position.x > 0) {
			player->direction = DIR_LEFT_MOVING;
			player->position.x--;
		}
		if (btn == BTN_RIGHT && player->position.x < 15) {
			player->direction = DIR_RIGHT_MOVING;
			player->position.x++;
		}
		if (btn == BTN_UP && player->position.y > 0) {
			player->direction = DIR_FRONT;
			player->position.y--;
		}
		if (btn == BTN_DOWN && player->position.y < 1) {
			player->direction = DIR_BACK;
			player->position.y++;
		}

		lcd_create_char(PLAYER_ID, player->sides[player->direction]);

		lcd_goto(player->prev_position.y, player->prev_position.x);
		lcd_data(location->field[player->prev_position.y][player->prev_position.x]);
		
		lcd_goto(player->position.y, player->position.x);
		lcd_data(PLAYER_ID);

		_delay_ms(150);
	}
	else {
		switch (player->direction) {
			case DIR_RIGHT_MOVING:
				player->direction = DIR_RIGHT;
				break;
			case DIR_LEFT_MOVING: 
				player->direction = DIR_LEFT;
				break;
			default: 
				break;
		}
		lcd_create_char(PLAYER_ID, player->sides[player->direction]);

		lcd_goto(player->position.y, player->position.x);
		lcd_data(PLAYER_ID);
	}
}	
