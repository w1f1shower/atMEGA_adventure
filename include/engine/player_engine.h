#ifndef PLAYER_ENGINE_H
#define PLAYER_ENGINE_H

enum {
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_LEFT_MOVING,
	DIR_RIGHT,
	DIR_RIGHT_MOVING
};

void player_control(struct creature *player, const struct map *map, uint8_t btn);

#endif
