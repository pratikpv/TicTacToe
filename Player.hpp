#ifndef __PLAYER_H_INCLUDED
#define __PLAYER_H_INCLUDED

class Board;

#include "Player.hpp"
#include <cstring>
#include <iostream>
#include "cstdlib"
#include "common.hpp"

class Player {

private:

	PLAYER_TYPE player_t;
	char ticker;
	int move;
	Board *board;

public:

	Player(PLAYER_TYPE player_t, char ticker);
	PLAYER_TYPE get_player_type();
	char get_ticker();
	void set_board(Board *board);
	void make_player_move();

};

#endif
