#ifndef PLAYER_H
#define PLAYER_H


struct creature player = {
	position: {
		x: 8,
		y: 1
	},
	prev_position: {
		x: 0,
		y: 0
	},

	id: PLAYER_ID,
	direction: DIR_FRONT,
	sides: {
		{ /*| DIR_FRONT |*/
			0b00000,
			0b00100,
			0b01110,
			0b01110,
			0b01110,
			0b01010,
			0b01010,
			0b00000
		},
		{ /*| DIR_BACK |*/
			0b00000,
			0b00100,
			0b01110,
			0b01110,
			0b01110,
			0b01010,
			0b01010,
			0b00000
		},
		{ /*| DIR_LEFT |*/
			0b00000,
			0b00100,
			0b01110,
			0b01110,
			0b01110,
			0b01100,
			0b01100,
			0b00000
		},
		{ /*| DIR_LEFT_MOVING |*/
			0b00000,
			0b00100,
			0b01110,
			0b01110,
			0b01110,
			0b01100,
			0b01010,
			0b00000
		},
		{ /*| DIR_RIGHT |*/
			0b00000,
			0b00100,
			0b01110,
			0b01110,
			0b01110,
			0b00110,
			0b00110,
			0b00000
		},
		{ /*| DIR_RIGHT_MOVING |*/
			0b00000,
			0b00100,
			0b01110,
			0b01110,
			0b01110,
			0b00110,
			0b01010,
			0b00000
		}
	}
};

#endif
