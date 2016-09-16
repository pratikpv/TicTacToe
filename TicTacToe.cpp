using namespace std;

#include <iostream>
#include "common.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main() {

	Player p1 = Player(COMPUTER, 'X');
	Player p2 = Player(HUMAN, 'O');
	Board board = Board(&p1,&p2);

	board.show_welcome_messages();
	board.draw_board();

	while( !board.is_game_over()) {

		board.toggle_player_turn();
		board.make_board_move();
		board.draw_board();

	}
	
	board.declare_winner();
	return 0;
}
