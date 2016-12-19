#ifndef __BCURSES_H_INCLUDED
#define __BCURSES_H_INCLUDED

#include <string>

class Bcurses {

public:

	static const string RST;
	static const string KRED;
	static const string KGRN;
	static const string KYEL;
	static const string KBLU;
	static const string KMAG;
	static const string KCYN;
	static const string KWHT;

	static const string PLAY1_COLOR;
	static const string PLAY2_COLOR;
	static const string BOARD_COLOR;
	static const int ERASE_BOARD;

	static string BColor(string c);
	static string BColor(char c, char cpt);
	static void Erase_lines(int num);

};

#endif
