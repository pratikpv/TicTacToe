#ifndef __BOARD_H_INCLUDED
#define __BOARD_H_INCLUDED

/* Forward declaration */
class Player;

#include <cstring>
#include <iostream>
#include "cstdlib"
#include "common.hpp"

#define BOARD_SIZE	9
#define INIT_CHAR	' '

class Board {

private:

	char board_area[BOARD_SIZE];
	char template_board[BOARD_SIZE];
	Player *player1;
	Player *player2;
	Player *winner;

public:

	Player *turn;
	enum BOARD_ERROR {
		NO_ERROR = 0, OUT_OF_BOARD, ALREADY_USED_SPACE
	};

	Board(Player *player1, Player *player2);
	void draw_board();
	void draw_board(char *template_board);
	void show_welcome_messages();
	bool is_game_over();
	void declare_winner();
	void make_board_move();
	int validate_move(int move);
	void set_move(int move);
	Player *get_last_player();
	void toggle_player_turn();
	char * get_board_area();

};

#endif
