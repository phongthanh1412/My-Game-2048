#include"functions.h"
#include"prepareForGame.h"

// Hàm xác định toạ độ các dòng chữ, bảng
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm tô màu sắc
void printWithColor(const string& color, const string& text) {
    cout << color << text << RESET << endl;
}

// Hàm quay về màn hình chính
void backToMenu(char back, int idx) {
    do {
        back = _getch();
    } while (back != 13);
    system("cls");
    mainMenuScreen(idx);
}

// Tô màu toàn màn hình 
void colorScreen(const string& color, int time) {

    system("cls");
    for (int i = 0; i < 45; i++) {
        cout << color;
        for (int j = 0; j < 168; j++) {
            cout << " ";
        }
        this_thread::sleep_for(std::chrono::milliseconds(time));
    }
}

void menuIntroduce(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name, string& password, int& score, bool& canUndo, bool& canRedo, float& time, int& tableSize) {
    gotoxy(75, 20);
    cout << YELLOW << "GET STARTED!";
    char enter;
    do {
        enter = _getch();
    } while (enter != 13);
    colorScreen(COLOR_BACKGROUND_d, 0.5);
    colorScreen(RESET, 1);
    system("cls");
    string text[] = {
       "                 *                                                                                                           *                                              ",
       "   *              *             ******************************************************************************************************                        *    *  ",
       "                                    ________  ________  _____ ______   _______            _______  ________  ___   ___  ________                           *",
       "            *                      |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  __* \\          /  ___  \\|\\   __  \\|\\  \\ |\\  \\|\\   __  \\           *",
       "                   *               \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        /__/|_/  /\\ \\  \\|\\  \\ \\  \\\\_\\  \\ \\  \\|\*\  \\*",
       "      *                             \\ \\  \\  __\\ \\  *__  \\ \\  \\\\|__| \\  \\ \\  \\_|/__      |__|//  / /\\ \\  \\\\\\  \\ \\______  \\ \\   __  \\ *     *",
       "                   *              *  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\  * \\ \\  \\ \\  \\_|\\ \\         /  /_/__\\ \\  \\\\\\  \\|_____|\\  \\ \\  \\|\\  \\*",
       "                                      \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       |\\________\\ \\_______\\     \\ \\__\\ \\_______\\ *",
       "           *                *          \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|_______|\\|_______|      \\|__|\\|_______|              *"
       "                                                                       *                     *                                                               *",
       "                                ******************************************************************************************************                       *",
       "                                                                                                                           *                                           ",
    };
    // Mảng màu sắc
    string colors[] = { RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };
    int pos = 12;
    system("cls");
    bool isEntered = 0;
    while (!isEntered) {
        for (int i = 0; i < 7; i++) {
            gotoxy(0, pos);
            for (const string& line : text) {
                printWithColor(colors[i], line);
            }
            this_thread::sleep_for(500ms);
            // Hàm để kiểm tra xem người dùng đã nhấn Enter chưa để bắt đầu đi đến menu 
            if (_kbhit()) { 
                char button = _getch(); 
                if (button == 13) { 
                    isEntered = 1;
                    break; 
                }
            }
        }
    }
    colorScreen(COLOR_BACKGROUND_d, 0.5);
    colorScreen(RESET, 1);
    system("cls");
    prepareForGame(playerList, gameplay, name, password, score, canUndo, canRedo, time, tableSize);
}