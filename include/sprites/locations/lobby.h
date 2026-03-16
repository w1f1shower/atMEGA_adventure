struct location lobby = {
	cell_data: { 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP,   STP, STP, STP, FORGD, FORGD }, 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, UNSTP, STP, STP, STP, FORGD, FORGD }
	},
	field: {
			{ ' ', ' ', ' ', ' ', 'L', 'o', 'b', 'b', 'y', ' ', ' ',  ' ', ' ', ' ', LOCATION_FRAME_ID1, LOCATION_FRAME_ID2 },
			{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 0xFF, ' ', ' ', ' ', LOCATION_FRAME_ID3, LOCATION_FRAME_ID4 }
	}
};

uint8_t tree[4][8] = {
	{
		0b00000,
		0b00011,
		0b00100,
		0b01000,
		0b01011,
		0b00100,
		0b01000,
		0b01000
	},
	{
		0b11000,
		0b00110,
		0b00001,
		0b00001,
		0b11001,
		0b00110,
		0b00001,
		0b00010
	},
	{
		0b00100,
		0b00011,
		0b00000,
		0b00001,
		0b00000,
		0b00000,
		0b00011,
		0b01111
	},
	{
		0b01100,
		0b10000,
		0b11100,
		0b10000,
		0b11000,
		0b10000,
		0b11000,
		0b11100
	}
};

struct object crate = {
	position: {
		x: 3,
		y: 1
	},
	id: 0xDB,
};


