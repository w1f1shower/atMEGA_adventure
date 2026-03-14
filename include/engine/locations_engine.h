#ifndef LOCATIONS_ENGINE_H
#define LOCATIONS_ENGINE_H

/*| TODO: enum as btmask for all cell options |*/
enum {
	CELL_STP,	/*| Cell is steppable	  |*/
	CELL_UNSTP	/*| Cell is not steppable |*/	

	/*| TODO:	 |*
	 *| CELL_MOVABLE |*
	 *| CELL_UNIQUE	 |*
	 *| CELL_DOOR	 |*/
};

struct location {
	uint8_t	    cell_data[2][16];	/*| buffer for data about location's field	|*/
	const uint8_t	field[2][16]; 	/*| buffer for textures 			|*/
};

uint8_t location_init(struct location *location, uint8_t uniq_chars[][8]);

#endif
