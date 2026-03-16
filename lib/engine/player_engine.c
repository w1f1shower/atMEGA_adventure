/*
void player_move(struct creature *player, struct location *location, uint8_t btn) {
	
}
*/

void player_control(struct creature *player, struct location *location, uint8_t btn) {
	if (btn != BTN_NONE ) {
		player->prev_position.x = player->position.x;
		player->prev_position.y = player->position.y;

		switch (btn) {
			case BTN_LEFT: 
				player->direction = DIR_LEFT_MOVING;
				if (player->position.x > 0 &&
					location->cell_data
						[player->position.y]
						[player->position.x-1] 
							< UNSTP)
						player->position.x--;
				break;
			case BTN_RIGHT: 
				player->direction = DIR_RIGHT_MOVING;
				if (player->position.x < 15 &&
					location->cell_data
						[player->position.y]
						[player->position.x+1]
							< UNSTP)
						player->position.x++;
				break;
			case BTN_UP: 
				player->direction = DIR_FRONT;
				if (player->position.y > 0 &&
					location->cell_data
						[player->position.y-1]
						[player->position.x] 
							< UNSTP)
						player->position.y--;
				break;
			case BTN_DOWN: 
				player->direction = DIR_BACK;
				if (player->position.y < 15 &&
					location->cell_data
						[player->position.y+1]
						[player->position.x]
							< UNSTP)
						player->position.y++;
				break;
			case BTN_SELECT: default: break;
		}
		_delay_ms(200);
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
	}
	switch (location->cell_data[player->position.y][player->position.x]) {
		case STP: case BCKGD:
			lcd_create_char(PLAYER_ID, player->sides[player->direction]);
			lcd_goto(player->position.y, player->position.x);
			lcd_data(PLAYER_ID);
		case FORGD:
			if (player->prev_position.y != player->position.y || 
			    player->prev_position.x != player->position.x) {
				lcd_goto(player->prev_position.y, player->prev_position.x);
				lcd_data(location->field[player->prev_position.y][player->prev_position.x]);
			}
		default: break;
	}
}	
