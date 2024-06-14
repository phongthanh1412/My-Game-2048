#include"functions.h"
#include "prepareForGame.h"

void menuSetting(int idx) {

    gotoxy(51, 10);
    cout << "   ____                                 _   _   _                 " << endl;
    gotoxy(51, 11);
    cout << "  / ___| __ _ _ __ ___   ___   ___  ___| |_| |_(_)_ __   __ _ ___ " << endl;
    gotoxy(51, 12);
    cout << " | |  _ / _` | '_ ` _ \\ / _ \\ / __|/ _ \\ __| __| | '_ \\ / _` / __| " << endl;
    gotoxy(51, 13);
    cout << " | |_| | (_| | | | | | |  __/ \\__ \\  __| |_| |_| | | | | (_| \\__ \\ " << endl;
    gotoxy(51, 14);
    cout << "  \\____|\\__,_|_| |_| |_|\\___| |___/\\___|\\__|\\__|_|_| |_|\\__, |___/ " << endl;
    gotoxy(51, 15);
    cout << "                                                        |___/      " << endl;
    const char* title[] = {
            "         Switch on undo/redo mode            ",
            "         Switch on undo mode                 ",
            "         Set the size of the grid            ",
            "         Go back to main menu screen         ",
    };
    int size = sizeof(title) / sizeof(title[0]);
    int pos = 21;
    gotoxy(60, 18);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_n << WHITE << "                  Options                      " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(60, 19);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_n << "                                               " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(60, 20);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_c << "                                               " << COLOR_BACKGROUND_n << "  " << RESET << endl;

    for (int i = 0; i < size; i++) {
        gotoxy(60, pos + i * 2); // Tăng khoảng cách giữa các dòng
        if (i == idx) {
            cout << COLOR_BACKGROUND_n << "  " << RESET << COLOR_BACKGROUND_l << WHITE << title[i] << "  " << COLOR_BACKGROUND_n << "  " << RESET << endl;
        }
        else {
            cout << COLOR_BACKGROUND_n << "  " << RESET << COLOR_BACKGROUND_c << BLACK << title[i] << "  " << RESET << COLOR_BACKGROUND_n << "  " << RESET << endl;
        }
        gotoxy(60, pos + i * 2 + 1); // Thêm dòng trống giữa các mục
        cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_c << "                                               " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    }

    gotoxy(60, pos + size * 2);
    cout << COLOR_BACKGROUND_n << setw(51) << " " << RESET << endl;
}
