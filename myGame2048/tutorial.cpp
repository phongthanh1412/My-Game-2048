#include"functions.h"
#include "prepareForGame.h"

void tutorial()
{
    gotoxy(65, 4);
    cout << " _____      _             _       _ " << endl;
    gotoxy(65, 5);
    cout << "|_   __   _| |_ ___  _ __(_) __ _| |" << endl;
    gotoxy(65, 6);
    cout << "  | || | | | __/ _ \\| '__| |/ _` | |" << endl;
    gotoxy(65, 7);
    cout << "  | || |_| | || (_) | |  | | (_| | |" << endl;
    gotoxy(65, 8);
    cout << "  |_| \\__,_|\\__\\___/|_|  |_|\\__,_|_|" << endl;
    gotoxy(33, 11);
    cout << COLOR_BACKGROUND_n << setw(104) << " " << RESET << endl;
    gotoxy(33, 12);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 13);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 14);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 15);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 16);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 17);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 18);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 19);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 20);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 21);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 22);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 23);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 24);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 25);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 26);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 27);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << setw(100) << " " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(33, 28);
    cout << COLOR_BACKGROUND_n << setw(104) << " " << RESET << endl;
    cout << "\033[15;37H" << COLOR_BACKGROUND_p << RED << "::[ Tutorial ]::" << endl;
    cout << "\033[15;57H" << COLOR_BACKGROUND_p << RED << "   Law of game: In this game, players merge tiles containing the same numbers " << RESET << endl;
    cout << "\033[16;57H" << COLOR_BACKGROUND_p << RED << "   until they achieve the value 2048. Tiles exclusively accommodate integer" << RESET << endl;
    cout << "\033[17;57H" << COLOR_BACKGROUND_p << RED << "   values starting from 2, which are powers of 2, such as 2, 4, 8, 16, 32 " << RESET << endl;
    cout << "\033[18;57H" << COLOR_BACKGROUND_p << RED << "   64, 128, etc." << RESET << endl;
    cout << "\033[19;37H" << COLOR_BACKGROUND_p << RED << "--------------------------------------------------------------------------------------------------" << RESET;
    cout << "\033[22;37H" << COLOR_BACKGROUND_p << RED << "::[ Control ]::" << RESET << endl;
    cout << "\033[22;77H" << COLOR_BACKGROUND_p << RED << "n - Restart" << RESET << endl;
    cout << "\033[24;77H" << COLOR_BACKGROUND_p << RED << "e - Exit game" << RESET << endl;
    cout << "\033[22;97H" << COLOR_BACKGROUND_p << RED << "u - Undo" << RESET << endl;
    cout << "\033[24;97H" << COLOR_BACKGROUND_p << RED << "r - Redo" << RESET << endl;
    cout << "\033[24;44H" << COLOR_BACKGROUND_p << RED << "w " << RESET << endl;
    cout << "\033[26;44H" << COLOR_BACKGROUND_p << RED << "s " << RESET << endl;
    cout << "\033[25;40H" << COLOR_BACKGROUND_p << RED << "a " << RESET << endl;
    cout << "\033[25;48H" << COLOR_BACKGROUND_p << RED << "d " << RESET << endl;
}