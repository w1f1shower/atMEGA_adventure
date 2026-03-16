uint8_t object_init(struct object *object){
	if (object->position.x > 16 || object->position.y > 2) {
		return 1;
	}

	lcd_goto(object->position.y, object->position.x);
	lcd_data(object->id);
	return 0;
}
void object_control(struct object *object, struct creature *player, struct location *location) {
	if (object->position.x == player->position.x && object->position.y == player->position.y) {
		switch (player->direction) {
			case DIR_LEFT_MOVING: case DIR_LEFT: 
				if (object->position.x > 0 &&
				    location->cell_data
				    	[object->position.y]
					[object->position.x-1] < FORGD)
				object->position.x--;
				break;
			case DIR_RIGHT_MOVING: case DIR_RIGHT:
				if (object->position.x < 15 &&
				    location->cell_data
				    	[object->position.y]
					[object->position.x+1] < FORGD)
				object->position.x++;
				break;
		}
	}
	else {
		lcd_goto(object->position.y, object->position.x);
		lcd_data(object->id);
	}
}
