using namespace std;

#include <iostream>
#include "Common.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main() {

	Player p1 = Player(HUMAN, 'O');
	Player p2 = Player(COMPUTER, 'X');
	Board board = Board(&p1,&p2);
	bool clear = false;

	board.show_welcome_messages();
	board.draw_board(clear);

	while( !board.is_game_over()) {

		board.toggle_player_turn();
		board.make_board_move();
		board.draw_board();

	}

	board.declare_winner();
	return 0;

}
