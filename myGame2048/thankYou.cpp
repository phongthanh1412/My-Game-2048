#include"prepareForGame.h"

void sayThanks() {
	colorScreen(COLOR_BACKGROUND_d, 0.5);
	colorScreen(RESET, 1);
	system("cls");
	gotoxy(50, 13);
	cout << " _____ _   _   ___   _   _  _   __    __   _______ _   _    _ " << endl;
	gotoxy(50, 14);
	cout << "|_   _| | | | / _ \\ | \\ | || | / /    \\ \\ / /  _  | | | |  | |" << endl;
	gotoxy(50, 15);
	cout << "  | | | |_| |/ /_\\ \\|  \\| || |/ /      \\ V /| | | | | | |  | |" << endl;
	gotoxy(50, 16);
	cout << "  | | |  _  ||  _  || . ` ||    \\       \\ / | | | | | | |  | |" << endl;
	gotoxy(50, 17);
	cout << "  | | | | | || | | || |\\  || |\\  \\      | | \\ \\_/ / |_| |  |_|" << endl;
	gotoxy(50, 18);
	cout << "  \\_/  \\_| |_/_| |_/\\_| \\_/\\_| \\_/      \\_/  \\___/ \\___/   (_)" << endl;
	gotoxy(60, 21);
	cout << COLOR_BACKGROUND_l << WHITE << "      Press 'Enter' to login account...      " << RESET;
	gotoxy(60, 23);
	cout << COLOR_BACKGROUND_l << WHITE << "         Press e to exit the game!           " << RESET;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

}
