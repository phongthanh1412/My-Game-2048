#include"functions.h"
#include "prepareForGame.h"

void display_menu(gamePlay2048& gameplay, string& name, int x, int y, int tableSize)
{
    y = 12;
    x += 2; // Tăng x để tạo khoảng cách từ lề trái
    y++;    // Tăng y để di chuyển xuống một dòng

    // In viền trên cùng
    gotoxy(x, y++);
    for (int j = 0; j < tableSize; j++) {
        cout << BLACK << COLOR_BACKGROUND_BORDER << setw(12) << " " << RESET;
    }
    cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET; // Viền phải cùng
    gotoxy(x, y++);

    for (int i = 0; i < tableSize; i++) {
        // In viền trái cùng và nội dung của ô
        cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
        for (int j = 0; j < tableSize; j++) {
            if (gameplay.table[i][j] == 0) {
                cout << COLOR_BACKGROUND_a << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 2) {
                cout << COLOR_BACKGROUND_b << BLACK << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 4) {
                cout << COLOR_BACKGROUND_c << BLACK << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 8) {
                cout << COLOR_BACKGROUND_d << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 16) {
                cout << COLOR_BACKGROUND_e << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 32) {
                cout << COLOR_BACKGROUND_f << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 64) {
                cout << COLOR_BACKGROUND_g << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] >= 128) {
                cout << COLOR_BACKGROUND_h << BLACK << setw(10) << " " << RESET;
            }
            // Viền dọc giữa các ô
            cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
        }
        gotoxy(x, y++);

        // In viền trái cùng và giá trị của ô
        cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
        for (int j = 0; j < tableSize; j++) {
            if (gameplay.table[i][j] == 0) {
                cout << BLACK << COLOR_BACKGROUND_a;
                cout << setw(10) << " ";
            }
            else {
                if (gameplay.table[i][j] == 2) {
                    cout << BLACK << COLOR_BACKGROUND_b;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
                else if (gameplay.table[i][j] == 4) {
                    cout << BLACK << COLOR_BACKGROUND_c;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
                else if (gameplay.table[i][j] == 8) {
                    cout << WHITE << COLOR_BACKGROUND_d;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
                else if (gameplay.table[i][j] == 16) {
                    cout << WHITE << COLOR_BACKGROUND_e;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
                else if (gameplay.table[i][j] == 32) {
                    cout << WHITE << COLOR_BACKGROUND_f;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
                else if (gameplay.table[i][j] == 64) {
                    cout << WHITE << COLOR_BACKGROUND_g;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
                else if (gameplay.table[i][j] >= 128) {
                    cout << WHITE << COLOR_BACKGROUND_h;
                    cout << setw(5) << right << gameplay.table[i][j] << setw(5) << " ";
                }
            }
            cout << RESET;
            cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
        }
        gotoxy(x, y++);

        // In viền trái cùng và phần dưới của ô
        cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
        for (int j = 0; j < tableSize; j++) {
            if (gameplay.table[i][j] == 0) {
                cout << COLOR_BACKGROUND_a << BLACK << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 2) {
                cout << COLOR_BACKGROUND_b << BLACK << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 4) {
                cout << COLOR_BACKGROUND_c << BLACK << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 8) {
                cout << COLOR_BACKGROUND_d << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 16) {
                cout << COLOR_BACKGROUND_e << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 32) {
                cout << COLOR_BACKGROUND_f << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] == 64) {
                cout << COLOR_BACKGROUND_g << WHITE << setw(10) << " " << RESET;
            }
            else if (gameplay.table[i][j] >= 128) {
                cout << COLOR_BACKGROUND_h << WHITE << setw(10) << " " << RESET;
            }
            cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
        }
        gotoxy(x, y++);

        // In đường viền ngang giữa các hàng
        if (i != tableSize) {
            cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET;
            for (int j = 0; j < tableSize; j++) {
                cout << BLACK << COLOR_BACKGROUND_BORDER << setw(10) << " " << RESET;
                cout << BLACK << COLOR_BACKGROUND_BORDER << setw(2) << " " << RESET; // Đường viền dọc
            }
            gotoxy(x, y++);
        }
    }

    gotoxy(2, 8);
    cout << COLOR_BACKGROUND_l << setw(32) << " " << RESET << endl;
    gotoxy(2, 9);
    cout << COLOR_BACKGROUND_l << "  " << COLOR_BACKGROUND_c << BLACK << setw(10) << left << "Player: " << setw(18) << left << name << COLOR_BACKGROUND_l << "  " << RESET << endl;
    gotoxy(2, 10);
    cout << COLOR_BACKGROUND_l << "  " << COLOR_BACKGROUND_c << BLACK << setw(10) << left << "Scores: " << setw(18) << left << gameplay.score << COLOR_BACKGROUND_l << "  " << RESET << endl;
    gotoxy(2, 11);
    cout << COLOR_BACKGROUND_l << setw(32) << " " << RESET << endl;

    gotoxy(0, 1);
    cout << COLOR_BACKGROUND_n << "                                                                                " << RESET << endl;
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "                 ::[ Control ]::                     ::[Move]::             " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "       n - Restart         e - Exit game                  w                 " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "       u - Undo            r - Redo                  a    o    d            " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "                                                          s                 " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    cout << COLOR_BACKGROUND_n << "-                                                                              -" << RESET << endl;
    cout << endl;

    gotoxy(82, 2);
    cout << COLOR_BACKGROUND_n << "                              " << RESET << endl;
    gotoxy(82, 3);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << "   ::[ GAME 2048 ]::      " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(82, 4);
    cout << COLOR_BACKGROUND_n << "  " << COLOR_BACKGROUND_p << RED << " Progammed by Thanh Phong " << COLOR_BACKGROUND_n << "  " << RESET << endl;
    gotoxy(82, 5);
    cout << COLOR_BACKGROUND_n << "-                            -" << RESET << endl;
    cout << endl;

}