#ifndef CREATURES_ENGINE_H
#define CREATURES_ENGINE_H

struct creature {
	struct pos position; 	
	struct pos prev_position; 	
	uint8_t id;
	uint8_t direction;
	const uint8_t sides[][8];
};

uint8_t creature_init(struct creature *creature);

#endif
