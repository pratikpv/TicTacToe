#ifndef __PLAYER_H_INCLUDED
#define __PLAYER_H_INCLUDED

class Board;

#include "Player.hpp"
#include <cstring>
#include <iostream>
#include "cstdlib"
#include "Common.hpp"
#include <random>

class Player {

private:

	PLAYER_TYPE player_t;
	char ticker;
	int move;
	Board *board;
	int preffered_move_loc ;
	const int preffered_move[9] =  { 4, 0, 2,8,6,1,5,7,3};
	char name[MAX_NAME];
public:

	Player(PLAYER_TYPE player_t, char ticker);
	PLAYER_TYPE get_player_type();
	char get_ticker();
	char *get_name();
	void set_name(char *name);
	void set_board(Board *board);
	void make_player_move();
	int match_pair(int combination_3c2[3] , char board_area[BOARD_SIZE]);
};

#endif
