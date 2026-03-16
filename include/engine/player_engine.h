#ifndef PLAYER_ENGINE_H
#define PLAYER_ENGINE_H

enum {
	DIR_FRONT,
	DIR_BACK,
	DIR_LEFT,
	DIR_LEFT_MOVING,
	DIR_RIGHT,
	DIR_RIGHT_MOVING
};

void player_control(struct creature *player, struct location *location, uint8_t btn);

#endif
