#include"functions.h"
#include "prepareForGame.h"

void mainMenuScreen(int idx) {

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    gotoxy(0, 5);
    cout << "                                               _                            _                                                        " << endl;
    gotoxy(0, 6);
    cout << "                                              | |                          | |                                                       " << endl;
    gotoxy(0, 7);
    cout << "                                 __      _____| | ___ ___  _ __ ___   ___  | |_ ___    _ __ ___  _   _    __ _  __ _ _ __ ___   ___  " << endl;
    gotoxy(0, 8);
    cout << "                                 \\ \\ /\\ / / _ | |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | '_ ` _ \\| | | |  / _` |/ _` | '_ ` _ \\ / _ \\ " << endl;
    gotoxy(0, 9);
    cout << "                                  \\ V  V |  __| | (_| (_) | | | | | |  __/ | || (_) | | | | | | | |_| | | (_| | (_| | | | | | |  __/ " << endl;
    gotoxy(0, 10);
    cout << "                                   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |_| |_| |_|\\__, |  \\__, |\\__,_|_| |_| |_|\\___| " << endl;
    gotoxy(0, 11);
    cout << "                                                                                                  __/ |   __/ |                      " << endl;
    gotoxy(0, 12);
    cout << "                                                                                                 |___/   |___/                       " << endl;

    const char* title[] = {
        "        Tutorial           ",
        "        New Game           ",
        "        Game settings      ",
        "        Top-20 list        ",
        "        Resume             "
    };
    int size = sizeof(title) / sizeof(title[0]);
    int pos = 21;
    gotoxy(65, 18);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_n << WHITE << "          Options            " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(65, 19);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_n << "                             " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(65, 20);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_c << "                             " << COLOR_BACKGROUND_n << "  " << RESET << endl;

    for (int i = 0; i < size; i++) {
        gotoxy(65, pos + i * 2); // Tăng khoảng cách giữa các dòng
        if (i == idx) {
            cout << COLOR_BACKGROUND_n << "  " << RESET << COLOR_BACKGROUND_l << WHITE << title[i] << "  " << COLOR_BACKGROUND_n << "  " << RESET << endl;
        }
        else {
            cout << COLOR_BACKGROUND_n << "  " << RESET << COLOR_BACKGROUND_c << BLACK << title[i] << "  " << RESET << COLOR_BACKGROUND_n << "  " << RESET << endl;
        }
        gotoxy(65, pos + i * 2 + 1); // Thêm dòng trống giữa các mục
        cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_c << "                             " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    }

    gotoxy(65, pos + size * 2);
    cout << COLOR_BACKGROUND_n << setw(33) << " " << RESET << endl;
}