#include"functions.h"
#include "prepareForGame.h"

void menuResume() {
	gotoxy(62, 5);
	cout << "  _____                                 " << endl;
	gotoxy(62, 6);
	cout << " |  __ \\                                " << endl;
	gotoxy(62, 7);
	cout << " | |__) |___  ___ _   _ _ __ ___   ___  " << endl;
	gotoxy(62, 8);
	cout << " |  _  // _ \\/ __| | | | '_ ` _ \\ / _ \\ " << endl;
	gotoxy(62, 9);
	cout << " | | \\ \\  __/\\__ \\ |_| | | | | | |  __/ " << endl;
	gotoxy(62, 10);
	cout << " |_|  \\_\\___||___/\\__,_|_| |_| |_|\\___| " << endl;
	gotoxy(62, 11);
	cout << "                                        " << endl;
	gotoxy(58, 14);
	cout << COLOR_BACKGROUND_n << setw(52) << " " << RESET << endl;
	gotoxy(58, 15);
	cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "                                                " << COLOR_BACKGROUND_n << "  " << RESET << endl;
	gotoxy(58, 16);
	cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "        ::[ WELCOME TO MY 2048 GAME ]::         " << COLOR_BACKGROUND_n << "  " << RESET << endl;
	gotoxy(58, 17);
	cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "                                                " << COLOR_BACKGROUND_n << "  " << RESET << endl;
	gotoxy(58, 18);
	cout << COLOR_BACKGROUND_n << setw(52) << " " << RESET << endl;
}
