#ifndef LOCATIONS_ENGINE_H
#define LOCATIONS_ENGINE_H

/*| TODO: enum as btmask for all cell options |*/
enum {
	STP,	/*| Cell is steppable	  |*/
	BCKGD,	/*| Cell is background	  |*/
	FORGD,	/*| Cell is foreground	  |*/
	UNSTP	/*| Cell is not steppable |*/	
};

enum {
	PLAYER_ID = 0,
	CREATURE_ID1,
	CREATURE_ID2,
	OBJECT_ID,
	LOCATION_FRAME_ID1,
	LOCATION_FRAME_ID2,
	LOCATION_FRAME_ID3,
	LOCATION_FRAME_ID4
};

struct pos {
	uint8_t x;
	uint8_t y;
};

struct location {
	const uint8_t	field[2][16]; 	/*| buffer for textures 			|*/
	uint8_t	    cell_data[2][16];	/*| buffer for data about location's field	|*/
};


uint8_t location_init(struct location *location, uint8_t uniq_cells[][8]);

#endif
