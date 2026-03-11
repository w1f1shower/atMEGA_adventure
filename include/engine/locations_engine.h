#ifndef LOCATIONS_ENGINE_H
#define LOCATIONS_ENGINE_H

struct location {
	//uint8_t drawable[2][2];	/*| bitmap for drawable part of location	|*/
	//uint8_t steppable[2][2];	/*| bitmap for steppable part of location	|*/
	//uint8_t unique[2][2];		/*| bitmap for unique characters of location	|*/
	const uint8_t field[2][16]; 	/*| buffer for textures 			|*/
};

void location_init(struct location *location, uint8_t uniq_chars[][8]);

#endif
