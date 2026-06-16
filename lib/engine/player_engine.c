/*
void player_move(struct creature *player, struct location *location, uint8_t btn) {
	
}
*/
uint8_t location_init(struct location *location);

void player_control(struct creature *player, const struct map *map, uint8_t btn) {
	static uint8_t map_x = 0, map_y = 0; //maybe put somewhere else later

	if (btn != BTN_NONE ) {
		player->prev_position.x = player->position.x;
		player->prev_position.y = player->position.y;

		/*| Moving |*/
		switch (btn) {
			case BTN_LEFT: 
				player->direction = DIR_LEFT_MOVING;
				if (player->position.x > 0) {
					if (map->locations[map_x][map_y]->cell_data
						[player->position.y]
						[player->position.x-1] 
							< UNSTP)
						player->position.x--;
				}
				else {
					player->position.x = 15;
					if (map_x > 0 &&
					map->locations[map_x-1][map_y]->cell_data
						[player->position.y]
						[player->position.x]
							< UNSTP) {
						map_x--;
						location_init(map->locations[map_x][map_y]);
					}
				}
				break;

			case BTN_RIGHT: 
				player->direction = DIR_RIGHT_MOVING;
				if (player->position.x < 15) {
					if (map->locations[map_x][map_y]->cell_data
						[player->position.y]
						[player->position.x+1]
							< UNSTP)
						player->position.x++;
				}
				else {
					player->position.x = 0;
					if (map_x < 1 &&
					map->locations[map_x+1][map_y]->cell_data
						[player->position.y]
						[player->position.x]
							< UNSTP) {
						map_x++;
						location_init(map->locations[map_x][map_y]);
					}
				}
				break;

			case BTN_UP: 
				player->direction = DIR_UP;
				if (player->position.y > 0) {
					if (map->locations[map_x][map_y]->cell_data
						[player->position.y-1]
						[player->position.x] 
							< UNSTP)
						player->position.y--;
				}
				else if (map_y < 1 &&
					map->locations[map_x][map_y+1]->cell_data
						[player->position.y+1]
						[player->position.x]
							< UNSTP) {
					player->position.y = 1;
					map_y++;
					location_init(map->locations[map_x][map_y]);
				}
				break;

			case BTN_DOWN: 
				player->direction = DIR_DOWN;
				if (player->position.y < 1) {
					if (map->locations[map_x][map_y]->cell_data
						[player->position.y+1]
						[player->position.x]
							< UNSTP)
						player->position.y++;
				}
				else if (map_y > 0 &&
					map->locations[map_x][map_y-1]->cell_data
						[player->position.y-1]
						[player->position.x]
							< UNSTP) {
					player->position.y = 0;
					map_y--;
					location_init(map->locations[map_x][map_y]);
				}
				break;

			case BTN_SELECT: default: break;
		}
		_delay_ms(200);
	}
	else {
		/*| Changing to standing position |*/
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
	/*| Rendering: (Back/Fore)ground hanldling |*/
	switch (map->locations[map_x][map_y]
			->cell_data[player->position.y]
				   [player->position.x]) {
		case STP: case BCKGD:
			lcd_create_char(PLAYER_ID, player->sides[player->direction]);
			lcd_goto(player->position.y, player->position.x);
			lcd_data(PLAYER_ID);
		case FORGD:
			if (player->prev_position.y != player->position.y || 
			    player->prev_position.x != player->position.x) {
				lcd_goto(player->prev_position.y, player->prev_position.x);
				lcd_data(map->locations[map_x][map_y]
						 ->field[player->prev_position.y]
							[player->prev_position.x]);
			}
		default: break;
	}
}	
