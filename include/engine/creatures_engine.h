#ifndef CREATURES_ENGINE_H
#define CREATURES_ENGINE_H

enum {
	PLAYER_ID = 0,
	CREATURE_ID1,
	CREATURE_ID2,
	CREATURE_ID3,
	LOCATION_FRAME_ID1,
	LOCATION_FRAME_ID2,
	LOCATION_FRAME_ID3,
	LOCATION_FRAME_ID4
};

enum {
	DIR_FRONT,
	DIR_BACK,
	DIR_LEFT,
	DIR_LEFT_MOVING,
	DIR_RIGHT,
	DIR_RIGHT_MOVING
};

struct pos {
	uint8_t x;
	uint8_t y;
};

struct creature {
	struct pos position; 	
	struct pos prev_position; 	
	uint8_t id;
	uint8_t direction;
	const uint8_t sides[][8];
};

void creature_init(struct creature *creature);

#endif
