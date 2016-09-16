using namespace std;

class Board;

#include "Board.hpp"
#include "Player.hpp"
#include <cstring>
#include <iostream>
#include "cstdlib"
#include "common.hpp"

Player::Player(PLAYER_TYPE pt, char tk) {

	player_t = pt;
	ticker = tk;
	board = NULL;
	move = -1;

}

PLAYER_TYPE Player::get_player_type() {

	return player_t;

}

char Player::get_ticker() {

	return ticker;

}

void Player::set_board(Board *b) {

	board = b;

}

void Player::make_player_move() {

	if (board) {
		int valid_move = Board::OUT_OF_BOARD;
		while (valid_move != Board::NO_ERROR) {
			cout<< "Hello Player ( " << ticker <<" ) , enter the position number for your move : ";
			cin >> move;
			valid_move = board->validate_move(move);
			switch (valid_move) {
			case Board::NO_ERROR:
				board->set_move(move);
				break;
			case Board::ALREADY_USED_SPACE:
				cout << "Invalid move. " << move
						<< " is already played. Try again\n";
				break;
			case Board::OUT_OF_BOARD:
				cout << "Invalid move. " << move
						<< " is out of board area. Enter any value from 0 to 8. Try again\n";
				break;
			default:
				cout << "Invalid move. Try again\n";
			}
		}
	} else {
		cout << "Board not set for player";
		exit(-1);
	}

}
