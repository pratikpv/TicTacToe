using namespace std;

class Board;

#include "Board.hpp"
#include "Player.hpp"
#include <cstring>
#include <iostream>
#include "cstdlib"
#include "common.hpp"
#include "Permutation3.hpp"

Player::Player(PLAYER_TYPE player_t, char ticker) {

	this->player_t = player_t;
	this->ticker = ticker;
	board = NULL;
	move = -1;
	preffered_move_loc = 0;

}

PLAYER_TYPE Player::get_player_type() {

	return player_t;

}

char Player::get_ticker() {

	return ticker;

}

void Player::set_board(Board *board) {

	this->board = board;

}

void Player::make_player_move() {

	int valid_move = Board::OUT_OF_BOARD;

	if (board) {

		if (player_t == HUMAN) {

			while (valid_move != Board::NO_ERROR) {

				cout << "\nHello Player ( " << ticker
					<< " ) , enter the position number for your move : ";
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
		
			cout << "\nIts computer's turn, and the computer makes move now :";
			/* Lets think how we can apply artificial intelligence*/

			Player *list[2] = {  board->turn ,/* first see if Comupter can win*/
					      board->get_last_player() /*this time check if we can defend*/
					   };
			int **p;
			int diagonal_back[3] = { 0, 4, 8 };
			int diagonal_forward[3] = { 2, 4, 6 };
			
			for(int player_turn = 0; player_turn < 2 ; player_turn ++ ) {
			
				/* vertical */
				for (int i = 0; i < 3; i++) {
					int arr[3] = { i, i + 3, i + 6 };
					Permutation3 perm3 = Permutation3(arr);
					p = perm3.get_permutation_tupple();
					char * ba = board->get_board_area();
					for (int j = 0; j < 6; j++) {
						if ( (ba[p[j][0]] == list[player_turn]->ticker) &&
							(ba[p[j][(1)]] == list[player_turn]->ticker) ) {
							valid_move = board->validate_move(p[j][(2)]);
							if (valid_move 	== Board::NO_ERROR) {
								board->set_move(p[j][(2)]);
								return;
							}
						}
					}
				}

				/* horizontal */
				for (int i = 0; i < 9; i+=3) {
					int arr[3] = { i, i + 1, i + 2 };
					Permutation3 perm3 = Permutation3(arr);
					p = perm3.get_permutation_tupple();
					char * ba = board->get_board_area();
					for (int j = 0; j < 6; j++) {
						if ( (ba[p[j][0]] == list[player_turn]->ticker) &&
								(ba[p[j][(1)]] == list[player_turn]->ticker) ) {
							valid_move = board->validate_move(p[j][(2)]);
							if (valid_move == Board::NO_ERROR) {
								board->set_move(p[j][(2)]);
								return;
							}
						}
					}
				}

				/* diagonal back 0-->4-->8 */
				Permutation3 perm3_diag_b = Permutation3(diagonal_back);
				p = perm3_diag_b.get_permutation_tupple();
				char * ba = board->get_board_area();
				for (int j = 0; j < 6; j++) {
					if ( (ba[p[j][0]] == list[player_turn]->ticker) &&
							(ba[p[j][(1)]] == list[player_turn]->ticker)) {
						valid_move = board->validate_move(p[j][(2)]);
						if (valid_move == Board::NO_ERROR) {
							board->set_move(p[j][(2)]);
							return;
						}
					}
				}

				/* diagonal forward 2-->4-->6*/
				Permutation3 perm3_diag_for = Permutation3(diagonal_forward);
				p = perm3_diag_for.get_permutation_tupple();
				for (int j = 0; j < 6; j++) {
					if ( ( ba[p[j][0]] == list[player_turn]->ticker) &&
							( ba[p[j][(1)]] == list[player_turn]->ticker) ) {
						valid_move = board->validate_move(p[j][(2)]);
						if (valid_move == Board::NO_ERROR) {
							board->set_move(p[j][(2)]);
							return;
						}
					}
				}
			}

			/* make preffered moves. */

			for( int  i = preffered_move_loc ; i < BOARD_SIZE ; i++) {
				valid_move = board->validate_move( preffered_move[i]);
				if (valid_move == Board::NO_ERROR) {
					board->set_move(preffered_move[i]);
					preffered_move_loc = i ++;
					return;
				}
			}
		} 
	} else {
		
		cout << "Board not set for player";
		exit(-1);
	}
}
