#ifndef CREATURES_ENGINE_H
#define CREATURES_ENGINE_H

struct creature {
	struct pos loc_position; 	
	struct pos prev_loc_position; 	
	struct pos map_position;
	uint8_t id;
	uint8_t health;
	uint8_t attack;
	uint8_t direction;
	const uint8_t sides[][8];
};

uint8_t creature_init(struct creature *creature);

#endif
