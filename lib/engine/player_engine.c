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
