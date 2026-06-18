/*
void player_move(struct creature *player, struct location *location, uint8_t btn) {
	
}
*/
uint8_t location_init(struct location *location);

void player_control(struct creature *player, const struct map *map, uint8_t btn) {

	if (btn != BTN_NONE ) {
		player->prev_loc_position.x = player->loc_position.x,
		player->prev_loc_position.y = player->loc_position.y;

		/*| Moving |*/
		switch (btn) {
			case BTN_LEFT: 
				player->direction = DIR_LEFT_MOVING;
				if (player->loc_position.x > 0) {
					if (map->locations
							[player->map_position.x]
							[player->map_position.y]
						->cell_data
							[player->loc_position.y]
							[player->loc_position.x-1] 
					< UNSTP)
						player->loc_position.x--;
				}
				else {
					if (player->map_position.x > 0 &&
					map->locations
						[player->map_position.x-1]
						[player->map_position.y]
					->cell_data
						[player->loc_position.y][15]
					< UNSTP) {
						player->loc_position.x = 15;
						player->map_position.x--;
						location_init(map->locations[player->map_position.x][player->map_position.y]);
					}
				}
				break;

			case BTN_RIGHT: 
				player->direction = DIR_RIGHT_MOVING;
				if (player->loc_position.x < 15) {
					if (map->locations
							[player->map_position.x]
							[player->map_position.y]
						->cell_data
							[player->loc_position.y]
							[player->loc_position.x+1]
					< UNSTP)
						player->loc_position.x++;
				}
				else {
					if (player->map_position.x < 1 &&
					map->locations
						[player->map_position.x+1]
						[player->map_position.y]
					->cell_data
						[player->loc_position.y][0]
					< UNSTP) {
						player->loc_position.x = 0;
						player->map_position.x++;
						location_init(map->locations[player->map_position.x][player->map_position.y]);
					}
				}
				break;

			case BTN_UP: 
				player->direction = DIR_UP;
				if (player->loc_position.y > 0) {
					if (map->locations
							[player->map_position.x]
							[player->map_position.y]
						->cell_data
							[player->loc_position.y-1]
							[player->loc_position.x] 
					< UNSTP)
					player->loc_position.y--;
				}
				else if (player->map_position.y < 1 &&
					map->locations
						[player->map_position.x]
						[player->map_position.y+1]
					->cell_data
						[1][player->loc_position.x]
				< UNSTP) {
					player->loc_position.y = 1;
					player->map_position.y++;
					location_init(map->locations[player->map_position.x][player->map_position.y]);
				}
				break;

			case BTN_DOWN: 
				player->direction = DIR_DOWN;
				if (player->loc_position.y < 1) {
					if (map->locations
						[player->map_position.x]
						[player->map_position.y]
					->cell_data
						[player->loc_position.y+1]
						[player->loc_position.x]
					< UNSTP)
					player->loc_position.y++;
				}
				else if (player->map_position.y > 0 &&
					map->locations
						[player->map_position.x]
						[player->map_position.y-1]
					->cell_data
						[0][player->loc_position.x]
				< UNSTP) {
					player->loc_position.y = 0;
					player->map_position.y--;
					location_init(map->locations[player->map_position.x][player->map_position.y]);
				}
				break;

			case BTN_SELECT: default: break;
		}
		_delay_ms(200);
	}
	else {
		/*| Changing to standing loc_position |*/
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
	switch (map->locations[player->map_position.x][player->map_position.y]
			->cell_data[player->loc_position.y]
				   [player->loc_position.x]) {
		case STP: case BCKGD:
			lcd_create_char(PLAYER_ID, player->sides[player->direction]);
			lcd_goto(player->loc_position.y, player->loc_position.x);
			lcd_data(PLAYER_ID);
		case FORGD:
			if (player->prev_loc_position.y != player->loc_position.y || 
			    player->prev_loc_position.x != player->loc_position.x) {
				lcd_goto(player->prev_loc_position.y, player->prev_loc_position.x);
				lcd_data(map->locations[player->map_position.x][player->map_position.y]
						 ->field[player->prev_loc_position.y]
							[player->prev_loc_position.x]);
			}
		default: break;
	}
}	
