#include"functions.h"
#include"prepareForGame.h"

void gameOverScreen() {
    colorScreen(COLOR_BACKGROUND_g, 10);
    gotoxy(20, 15);
    cout << WHITE << "      _____          _____        ______  _______        ______                 _____     ____      ____      ______        _____   " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 16);
    cout << WHITE << "  ___|\\    \\     ___|\\    \\      |      \\/       \\   ___|\\     \\           ____|\\    \\   |    |    |    | ___|\\     \\   ___|\\    \\  " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 17);
    cout << WHITE << " /    /\\    \\   /    /\\    \\    /          /\\     \\ |     \\     \\         /     /\\    \\  |    |    |    ||     \\     \\ |    |\\    \\ " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 18);
    cout << WHITE << "|    |  |____| |    |  |    |  /     /\\   / /\\     ||     ,_____/|       /     /  \\    \\ |    |    |    ||     ,_____/||    | |    |" << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 19);
    cout << WHITE << "|    |    ____ |    |__|    | /     /\\ \\_/ / /    /||     \\--'\\_|/      |     |    |    ||    |    |    ||     \\--'\\_|/|    |/____/ " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 20);
    cout << WHITE << "|    |   |    ||    .--.    ||     |  \\|_|/ /    / ||     /___/|        |     |    |    ||    |    |    ||     /___/|  |    |\\    \\ " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 21);
    cout << WHITE << "|    |   |_,  ||    |  |    ||     |       |    |  ||     \\____|\\       |\\     \\  /    /||\\    \\  /    /||     \\____|\\ |    | |    |" << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 22);
    cout << WHITE << "|\\ ___\\___/  /||____|  |____||\\____\\       |____|  /|____ '     /|      | \\_____\\/____/ || \\ ___\\/___ / ||____ '     /||____| |____|" << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 23);
    cout << WHITE << "| |   /____ / ||    |  |    || |    |      |    | / |    /_____/ |       \\ |    ||    | / \\ |   ||   | / |    /_____/ ||    | |    |" << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 24);
    cout << WHITE << " \\|___|    | / |____|  |____| \\|____|      |____|/  |____|     | /        \\|____||____|/   \\|___||___|/  |____|     | /|____| |____|" << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 25);
    cout << WHITE << "   \\( |____|/    \\(      )/      \\(          )/       \\( |_____|/            \\(    )/        \\(    )/      \\( |_____|/   \\(     )/  " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 26);
    cout << WHITE << "    '   )/        '      '        '          '         '    )/                '    '          '    '        '    )/       '     '   " << endl;
    this_thread::sleep_for(25ms);
    gotoxy(20, 27);
    cout << WHITE << "        '                                                   '                                                    '                  " << endl;
    this_thread::sleep_for(1500ms);
    colorScreen(RESET, 10);
}