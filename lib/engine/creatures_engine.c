uint8_t creature_init(struct creature *creature) {

	if (creature->position.x > 16 || creature->position.y > 2) {
		return 1;
	}

	lcd_create_char(creature->id, creature->sides[creature->direction]);

	creature->prev_position.x = creature->position.x;
	creature->prev_position.y = creature->position.y;

	lcd_goto(creature->position.y, creature->position.x);
	return 0;
}
