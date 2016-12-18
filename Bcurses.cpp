using namespace std;

#include "Bcurses.hpp"
#include <string>
#include <iostream>

const string Bcurses::RST  = "\x1B[0m";
const string Bcurses::KRED = "\x1B[31m";
const string Bcurses::KGRN = "\x1B[32m";
const string Bcurses::KYEL = "\x1B[33m";
const string Bcurses::KBLU = "\x1B[34m";
const string Bcurses::KMAG = "\x1B[35m";
const string Bcurses::KCYN = "\x1B[36m";
const string Bcurses::KWHT = "\x1B[38m";

const string Bcurses::PLAY1_COLOR = KYEL;
const string Bcurses::PLAY2_COLOR = KCYN;
const string Bcurses::BOARD_COLOR = KWHT;
const int Bcurses::ERASE_BOARD = 6;

string Bcurses::BColor(std::string c) {

	string s;
	s = BOARD_COLOR;
	s +=  c ;
	s += RST;
	return s;

}

string Bcurses::BColor(char c, char cpt) {

	string s;
	if( cpt == c )
		s = PLAY1_COLOR;
	else
		s = PLAY2_COLOR;
	s +=  c ;
	s += RST;
	return s;

}

void Bcurses::Erase_lines(int num) {

	for (int i = 0 ;i < num ; i++ )
		cout << "\033[A\33[2K\r" ;

}

void Bcurses :: cout_sameline(string s) {

	cout << "\033[A\33[2K\r" << s ;

}

