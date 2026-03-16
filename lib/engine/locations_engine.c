uint8_t location_init(struct location *location, uint8_t uniq_cells[][8]) {
	lcd_command(0x80);
	for (uint8_t uniq = 0, id = LOCATION_FRAME_ID1; id <= LOCATION_FRAME_ID4; uniq++, id++) {
		lcd_create_char(id, uniq_cells[uniq]);
	}
	
	for (uint8_t row = 0; row < 2; row++) {
		for (uint8_t col = 0; col < 16; col++) {
			lcd_data(location->field[row][col]);
				if (col == 15) lcd_command(0xC0);
		}
	}
	return 0; /*| TODO: some err handling plz |*/
}
