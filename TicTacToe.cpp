using namespace std;

#include <iostream>
#include "Common.hpp"
#include "Board.hpp"
#include "Player.hpp"

int main() {

	Player p1 = Player(HUMAN, 'O');
	Player p2 = Player(COMPUTER, 'X');
	Board board = Board(&p1, &p2);

	board.get_players_name();
	board.set_up_difficulty_level();
	while( !board.is_game_over() ) {
		board.re_draw();
		board.toggle_player_turn();
		board.make_board_move();
	}

	board.re_draw();
	board.declare_winner();
	return 0;

}
