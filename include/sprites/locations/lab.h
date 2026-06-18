struct location lab00 = { //bottom left (start)
	cell_data: { 
		{ UNSTP, STP, UNSTP, STP, UNSTP, STP, STP, UNSTP, UNSTP, STP,   STP, UNSTP, STP, STP,   STP, UNSTP },
		{ STP,   STP, STP,   STP, STP,   STP, STP, STP,   STP,   UNSTP, STP, STP,   STP, UNSTP, STP, STP   }
	},
	field: {
		{ 255, ' ', 255, ' ', 255, ' ', ' ', 255, 255, ' ', ' ', 255, ' ', ' ', ' ', 255 },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 255, ' ', ' ', ' ', 255, ' ', ' ' }
	}
};
struct location lab01 = { //top left
	cell_data: { 
		{ STP,   STP, STP, STP,   STP, STP,   STP,   STP, UNSTP, UNSTP, STP, STP, STP,   STP,   STP,   STP }, 
		{ UNSTP, STP, STP, UNSTP, STP, UNSTP, UNSTP, STP, STP,   STP, UNSTP, STP, UNSTP, UNSTP, UNSTP, STP }
	},
	field: {
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 255, 255, '*', ' ', ' ', ' ', ' ', ' ' },
		{ 255, ' ', ' ', 255, ' ', 255, 255, ' ', ' ', ' ', 255, ' ', 255, 255, 255, ' ' }
	}
};
struct location lab10 = { //bottom right
	cell_data: { 
		{ STP, UNSTP, STP, STP, STP, STP, UNSTP, STP, STP,   STP, UNSTP, STP, UNSTP, STP, UNSTP, STP }, 
		{ STP, STP,   STP, STP, STP, STP, STP,   STP, UNSTP, STP, STP,   STP, STP,   STP,   STP, STP }
	},
	field: {
		{ ' ', 255, ' ', ' ', ' ', ' ', 255, ' ', ' ', ' ', 255, ' ', 255, ' ', 255, ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 255, ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
	}
};
struct location lab11 = { //top right
	cell_data: { 
		{ STP,   STP, STP,   STP,   STP,   STP, STP,   STP,   STP,   UNSTP, STP, STP, UNSTP, STP, STP,   STP }, 
		{ UNSTP, STP, UNSTP, UNSTP, UNSTP, STP, UNSTP, UNSTP, UNSTP, STP,   STP, STP, UNSTP, STP, UNSTP, STP }
	},
	field: {
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 255, ' ', ' ', 255, ' ', ' ', ' ' },
		{ 255, ' ', 255, 255, 255, ' ', 255, 255, 255, ' ', ' ', ' ', 255, ' ', 255, ' ' }
	}
};

struct object crate = {
	position: {
		x: 3,
		y: 1
	},
	id: 0xDB,
};

const struct map lab_map = {
	locations: {
		{&lab00, &lab01}, 
		{&lab10, &lab11}
	}

};
