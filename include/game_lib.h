#ifndef GAME_LIB_H
#define GAME_LIB_H

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>


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


struct location {
	//uint8_t drawable[2][2];	/*| bitmap for drawable part of location	|*/
	//uint8_t steppable[2][2];	/*| bitmap for steppable part of location	|*/
	//uint8_t unique[2][2];		/*| bitmap for unique characters of location	|*/
	const uint8_t field[2][16]; 	/*| buffer for textures 			|*/
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
void location_init(struct location *location, uint8_t uniq_chars[][8]);
void player_control(struct creature *player, struct location *location, uint8_t btn);
#endif
