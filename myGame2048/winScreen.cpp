#include"functions.h"
#include"prepareForGame.h"

void winGameScreen() {

	colorScreen(COLOR_BACKGROUND_r, 10);
	gotoxy(40, 15);
	cout << WHITE << " _____      _____        _____     ____   ____         _____            ____  _____   ______         " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 16);
	cout << WHITE << "|\\    \\    /    /|  ____|\\    \\   |    | |    |       |\\    \\   _____  |    ||\\    \\ |\\     \\        " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 17);
	cout << WHITE << "| \\    \\  /    / | /     /\\    \\  |    | |    |       | |    | /    /| |    | \\    \\| \\     \\       " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 18);
	cout << WHITE << "|  \\____\\/    /  //     /  \\    \\ |    | |    |       \\/     / |    || |    |  \\    \\  \\     |      " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 19);
	cout << WHITE << " \\ |    /    /  /|     |    |    ||    | |    |       /     /_  \\   \\/ |    |   |     \\  |    |      " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 20);
	cout << WHITE << "  \\|___/    /  / |     |    |    ||    | |    |      |     // \\  \\   \\ |    |   |      \\ |    |      " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 21);
	cout << WHITE << "      /    /  /  |\\     \\  /    /||    | |    |      |    |/   \\ |    ||    |   |    |\\ \\|    |      " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 22);
	cout << WHITE << "     /____/  /   | \\_____\\/____/ ||\\___\\_|____|      |\\ ___/\\   \\|   /||____|   |____||\\_____/|      " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 23);
	cout << WHITE << "    |`    | /     \\ |          | /| |    |    |      | |   | \\______/ ||    |   |    |/ \\|   ||      " << WHITE << endl;
	this_thread::sleep_for(25ms);
	gotoxy(40, 24);
	cout << WHITE << "    |_____|/       \\|__________|/  \\|____|____|       \\|___|/\\ |    | ||____|   |____|   |___|/      " << WHITE << endl;
	this_thread::sleep_for(1000ms);
	colorScreen(RESET, 10);
}