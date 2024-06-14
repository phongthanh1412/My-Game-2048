#include"functions.h"
#include "prepareForGame.h"

void menuLogin()
{
    gotoxy(65, 5);
    cout << "  _             _       " << endl;
    gotoxy(65, 6);
    cout << " | |           (_)      " << endl;
    gotoxy(65, 7);
    cout << " | | ___   __ _ _ _ __  " << endl;
    gotoxy(65, 8);
    cout << " | |/ _ \\ / _` | | '_ \\ " << endl;
    gotoxy(65, 9);
    cout << " | | (_) | (_| | | | | |" << endl;
    gotoxy(65, 10);
    cout << " |_|\\___/ \\__, |_|_| |_|" << endl;
    gotoxy(65, 11);
    cout << "           __/ |        " << endl;
    gotoxy(65, 12);
    cout << "          |___/         " << endl;
    gotoxy(55, 14);
    cout << COLOR_BACKGROUND_n << setw(52) << " " << RESET << endl;
    gotoxy(55, 15);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "                                                " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(55, 16);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "        ::[ WELCOME TO MY 2048 GAME ]::         " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(55, 17);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "                                                " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(55, 18);
    cout << COLOR_BACKGROUND_n << setw(52) << " " << RESET << endl;
}