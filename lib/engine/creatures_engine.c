uint8_t creature_init(struct creature *creature) {

	if (creature->loc_position.x > 16 || creature->loc_position.y > 2) {
		return 1;
	}

	lcd_create_char(creature->id, creature->sides[creature->direction]);

	creature->prev_loc_position.x = creature->loc_position.x;
	creature->prev_loc_position.y = creature->loc_position.y;

	lcd_goto(creature->loc_position.y, creature->loc_position.x);
	lcd_data(creature->id);
	return 0;
}
