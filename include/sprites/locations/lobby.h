struct location lobby00 = {
	cell_data: { 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }, 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }
	},
	field: {
		{ ' ', ' ', ' ', ' ', 'L', 'o', 'b', 'b', 'y', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '0', ' ', ' ', ' ', ' ' }
	}
};
struct location lobby01 = {
	cell_data: { 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }, 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }
	},
	field: {
		{ ' ', ' ', 'O', '_', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '0', '1', ' ', ' ', ' ', ' ' }
	}
};
struct location lobby10 = {
	cell_data: { 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }, 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }
	},
	field: {
		{ ' ', ' ', '0', '_', 'o', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '0', ' ', ' ', ' ', ' ' }
	}
};
struct location lobby11 = {
	cell_data: { 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }, 
		{ STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP, STP }
	},
	field: {
		{ ' ', ' ', ' ', ' ', 'L', 'o', 'b', 'b', 'y', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '1', '1', ' ', ' ', ' ', ' ' }
	}
};

struct object crate = {
	position: {
		x: 3,
		y: 1
	},
	id: 0xDB,
};

const struct map lobby_map = {
	locations: {
		{&lobby00, &lobby01}, 
		{&lobby10, &lobby11}
	}

};
