using namespace std;

#include "Board.hpp"
#include "Player.hpp"
#include <cstring>
#include <iostream>
#include "cstdlib"
#include "Bcurses.hpp"

Board::Board(Player *p1,  Player *p2) {

	player1 = p1;
	player2 = p2;

	player1->set_board(this);
	player2->set_board(this);

	std::memset(board_area, INIT_CHAR, sizeof(board_area));
	for(int i = 0 ; i < BOARD_SIZE ; i ++ )
		template_board[i] = '0' + i ;
	winner = NULL;
	turn = player2;

}

void Board::draw_board(bool clear) {

	char cpt = turn->get_ticker();

	cout << " "
		<< Bcurses::BColor(board_area[0], cpt)
		<< Bcurses::BColor(" | ")
		<< Bcurses::BColor(board_area[1], cpt)
		<< Bcurses::BColor(" | ")
		<< Bcurses::BColor(board_area[2], cpt);

	cout << "\n" << Bcurses::BColor("-----------");

	cout << "\n "
		<< Bcurses::BColor(board_area[3], cpt)
		<< Bcurses::BColor(" | ")
		<< Bcurses::BColor(board_area[4], cpt)
		<< Bcurses::BColor(" | ")
		<< Bcurses::BColor(board_area[5], cpt);

	cout << "\n" << Bcurses::BColor("-----------");

	cout << "\n "
		<< Bcurses::BColor(board_area[6], cpt)
		<< Bcurses::BColor(" | ")
		<< Bcurses::BColor(board_area[7], cpt)
		<< Bcurses::BColor(" | ")
		<< Bcurses::BColor(board_area[8], cpt);
	cout << "\n\n";

}

void Board::draw_board( char *template_board) {

	cout << "\n " << template_board[0] << " | " << template_board[1] << " | "
			<< template_board[2];
	cout << "\n-----------";
	cout << "\n " << template_board[3] << " | " << template_board[4] << " | "
			<< template_board[5];
	cout << "\n-----------";
	cout << "\n " << template_board[6] << " | " << template_board[7] << " | "
			<< template_board[8] << " \n";
}

void Board::show_welcome_messages() {

	cout << "\nWelcome to Tic-Tac-Toe!\n\nBelow is the sample board with positions. "
		<<	"Valid positions are from 0 to 8\n";
	draw_board(Board::template_board);
	cout << "\nSo lets get started. Here is your play ground\n\n";

}
bool Board::is_game_over() {

	int space_avail = false;

	/* check if anybody won */

	if (
		((board_area[0] == board_area[1])
			&& (board_area[1] == board_area[2])
				&& (board_area[2] == turn->get_ticker() )
		) ||
		((board_area[3] == board_area[4])
			&& (board_area[4] == board_area[5])
				&& (board_area[5] == turn->get_ticker() )
		) ||
		((board_area[6] == board_area[7])
			&& (board_area[7] == board_area[8])
				&& (board_area[8] == turn->get_ticker() )
		) ||
		((board_area[0] == board_area[3])
			&& (board_area[3] == board_area[6])
				&& (board_area[6] == turn->get_ticker() )
		) ||
		((board_area[1] == board_area[4])
			&& (board_area[4] == board_area[7])
				&& (board_area[7] == turn->get_ticker() )
		) ||
		((board_area[2] == board_area[5])
			&& (board_area[5] == board_area[8])
				&& (board_area[8] == turn->get_ticker() )
		) ||
		((board_area[0] == board_area[4])
			&& (board_area[4] == board_area[8])
				&& (board_area[8] == turn->get_ticker() )
		) ||
		((board_area[6] == board_area[4])
			&& (board_area[4] == board_area[2])
				&& (board_area[2] == turn->get_ticker() )
		)
		) {

		winner = turn;
		return true;
	}

	/* check for any space left on the board */

	for (int i = 0; i < BOARD_SIZE; i++) {
		if ((board_area[i] != player1->get_ticker())
				&& (board_area[i] != player2->get_ticker())) {
			space_avail = true;
			break;
		}
	}
	if (space_avail)
		return false;
	else
		return true;

}
void Board::redraw() {

	cout << "\033[2J\033[1;1H";
	show_welcome_messages();
	draw_board();

}

void Board::declare_winner() {

	if (winner)
		cout << " The winner is player "
			<<  Bcurses::BColor(winner->get_ticker(),
					winner->get_ticker())
			<< "\n";
	else
		cout << " Its tie\n";

}

void Board::make_board_move() {

	turn->make_player_move();

}

char * Board::get_board_area() {
	
	return board_area;

}

void Board::toggle_player_turn() {

	if (turn == player1)
		turn = player2;
	else
		turn = player1;

}

int Board::validate_move(int move) {

	if (!(move >= 0 && move <= BOARD_SIZE - 1))
		return Board::OUT_OF_BOARD;
	if ((board_area[move] == player1->get_ticker()
			|| (board_area[move] == player2->get_ticker())))
		return Board::ALREADY_USED_SPACE;
	return Board::NO_ERROR;

}

void Board::set_move(int move) {
	
	board_area[move] = turn->get_ticker();

}

Player* Board::get_last_player() {

	if (turn == player1)
		return player2;
	else
		return player1;

}
