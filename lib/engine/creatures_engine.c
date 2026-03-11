void creature_init(struct creature *creature) {
	lcd_create_char(creature->id, creature->sides[creature->direction]);

	creature->position.x = 8;
	creature->position.y = 1;

	creature->prev_position.x = creature->position.x;
	creature->prev_position.y = creature->position.y;

	lcd_goto(creature->position.y, creature->position.x);
}
