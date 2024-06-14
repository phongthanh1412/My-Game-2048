#include"functions.h"
#include"prepareForGame.h"
#include "gameLogic.h"

void prepareForGame(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name, string& password, int& score, bool& canUndo, bool& canRedo, float& time, int& tableSize) {
    canUndo = 0;
    canRedo = 0;
    int idx = 0;
    myStack undoStack, redoStack;
    mainMenuScreen(idx);
    char button, arrow;
    while (1) {
        button = _getch();
        // Nhấn Enter để chọn chỉ mục cần thực hiện
        if (button == 13) {
            // Xem hướng dẫn chơi game
            if (idx == 0) {
                system("cls");
                tutorial();
                char back = ' ';
                backToMenu(back, idx);
            }
            // Đi đến màn hình đăng nhập
            else if (idx == 1) {
                system("cls");
                menuLogin();
                char button;
                do
                {
                    button = _getch();
                } while (button != 13);
                if (button == 13) // Nhấn 'Enter' để bắt đầu nhập các thông tin sau đó chơi mới
                {
                    do
                    {
                        // Tên đăng nhập và mật khẩu hợp lệ thì không được bỏ trống
                        cout << "\033[21;75H" << COLOR_BACKGROUND_l << WHITE << "::[ Login ]::" << RESET;
                        bool isLoginName = 1;
                        cout << "\033[23;65H" << COLOR_BACKGROUND_l << WHITE << "   Enter your name:  " << RESET;
                        getline(cin, name);
                        // Nếu tên có không hợp lệ thì yêu cầu nhập lại
                        if (!isValidName(name))
                        {                           
                            cout << "\033[25;45H" << COLOR_BACKGROUND_g << WHITE << "                                                                                  " << RESET;                           
                            cout << "\033[26;45H" << COLOR_BACKGROUND_g << WHITE << "  Username must be between 1 and 14 characters long and can only contain numbers  " << RESET;                           
                            cout << "\033[27;45H" << COLOR_BACKGROUND_g << WHITE << "  and alphabetic characters. Special characters are not allowed!                  " << RESET;                           
                            cout << "\033[28;45H" << COLOR_BACKGROUND_g << WHITE << "                                                                                  " << RESET;
                            isLoginName = 0;
                        }
                        // Sau khi username hợp lệ thì bắt đầu nhập password
                        if (isLoginName)
                        {
                            gotoxy(45, 24);
                            cout << ERASE;
                            gotoxy(45, 25);
                            cout << ERASE;
                            gotoxy(45, 26);
                            cout << ERASE;
                            gotoxy(45, 27);
                            cout << ERASE;
                            gotoxy(45, 28);
                            cout << ERASE;
                            cout << "\033[25;65H" << COLOR_BACKGROUND_l << WHITE << "   Enter your password: " << RESET;
                            getline(cin, password);
                            // Nếu password trống thì báo lỗi yêu cầu nhập lại
                            bool isLoginPassword = 1;
                            if (password == "")
                            {
                                cout << "\033[27;65H";
                                cout << ERASE;
                                cout << "\033[27;65H" << COLOR_BACKGROUND_g << WHITE << "Password is invalid! Please enter a valid one!" << RESET;
                                isLoginPassword = 0;
                            }
                            // Nếu tên bị trùng thì báo lỗi yêu cầu nhập lại
                            if (isLoginPassword)
                            {
                                if (isExistInfo(gameplay, name, password, score))
                                {
                                    gotoxy(55, 25);
                                    cout << ERASE;
                                    gotoxy(55, 26);
                                    cout << ERASE;
                                    gotoxy(55, 27);
                                    cout << ERASE;
                                    gotoxy(55, 28);
                                    cout << ERASE;
                                    cout << "\033[27;65H" << COLOR_BACKGROUND_g << WHITE << "Your username already exists! Please login again!" << RESET;
                                }
                            }
                        }
                    } while (isExistInfo(gameplay, name, password, score) || password == "" || !isValidName(name));
                    cout << "\033[27;65H";
                    cout << ERASE;
                    cout << "\033[27;65H" << COLOR_BACKGROUND_r << WHITE << "         Login successfully!       " << RESET;
                    cout << "\033[29;65H" << COLOR_BACKGROUND_i << WHITE << "     Press 'Enter' to play game!   " << RESET;
                    char enter;
                    enter = _getch();
                    colorScreen(COLOR_BACKGROUND_d, 0.3);
                    colorScreen(RESET, 1);
                    system("cls");
                    init_table(gameplay, tableSize);
                }
                return;
            }
            // Đi đến phần cài đặt game
            else if (idx == 2) {
                int idx1 = 0;
                char set;
                system("cls");
                menuSetting(idx1);
                while (1) {
                    set = _getch();
                    if (set == 13) {
                        if (idx1 == 0) {
                            gotoxy(64, 32);
                            cout << COLOR_BACKGROUND_r << WHITE << "    Switch on undo/redo mode successfully    " << RESET;
                            canUndo = 1;
                            canRedo = 1;
                            menuSetting(idx1);
                        }
                        else if (idx1 == 1) {
                            gotoxy(64, 34);
                            cout << COLOR_BACKGROUND_r << WHITE << "    Switch on undo mode successfully         " << RESET;
                            canUndo = 1;
                            menuSetting(idx1);
                        }
                        else if (idx1 == 2) {
                            gotoxy(64, 36);
                            cout << COLOR_BACKGROUND_l << WHITE << "   Enter the size of grid you want:  " << RESET;
                            cin >> tableSize;
                            cin.ignore();
                            gameplay.tableSize = tableSize;
                            gotoxy(64, 38);
                            cout << COLOR_BACKGROUND_r << WHITE << "    You will play on a " << tableSize << " x " << tableSize << " grid " << RESET;
                            if (set == 13)
                            menuSetting(idx1);
                        }
                        else if (idx1 == 3) {
                            system("cls");
                            mainMenuScreen(idx);
                            break;
                        }
                    }
                    else {
                        char arrow1 = _getch();
                        if (arrow1 == 72) {
                            idx1 = (idx1 - 1 + 4) % 4;
                        }
                        else if (arrow1 == 80) {
                            idx1 = (idx1 + 1) % 4;
                        }
                        menuSetting(idx1);
                    }
                }
                system("cls");
                mainMenuScreen(idx);
            }
            // Xem top-20 list 
            else if (idx == 3) {
                system("cls");
                playerList.showTop_20List();
                char back = ' ';
                backToMenu(back, idx);
            }
            // Vào phần resume người chơi
            else if (idx == 4) {
                system("cls");
                menuResume();
                char button;
                do
                {
                    button = _getch();
                } while (button != 13);
                if (button == 13) // Nhấn 'Enter' để bắt đầu nhập các thông tin sau đó chơi mới
                {
                    do
                    {
                        // Tên đăng nhập và mật khẩu hợp lệ thì không được bỏ trống
                        cout << "\033[21;75H" << COLOR_BACKGROUND_l << WHITE << "::[ Resume ]::" << RESET;
                        bool isLoginName = 1;
                        cout << "\033[23;60H" << COLOR_BACKGROUND_l << WHITE << "   Enter your name:  " << RESET;
                        getline(cin, name);
                        // Nếu tên có không hợp lệ thì yêu cầu nhập lại
                        if (!isValidName(name))
                        {
                            cout << "\033[25;45H" << COLOR_BACKGROUND_g << WHITE << "                                                                                  " << RESET;
                            cout << "\033[26;45H" << COLOR_BACKGROUND_g << WHITE << "  Username must be between 1 and 14 characters long and can only contain numbers  " << RESET;
                            cout << "\033[27;45H" << COLOR_BACKGROUND_g << WHITE << "  and alphabetic characters. Special characters are not allowed!                  " << RESET;
                            cout << "\033[28;45H" << COLOR_BACKGROUND_g << WHITE << "                                                                                  " << RESET;
                            isLoginName = 0;
                        }
                        // Sau khi username hợp lệ thì bắt đầu nhập password
                        if (isLoginName)
                        {
                            gotoxy(45, 24);
                            cout << ERASE;
                            gotoxy(45, 25);
                            cout << ERASE;
                            gotoxy(45, 26);
                            cout << ERASE;
                            gotoxy(45, 27);
                            cout << ERASE;
                            gotoxy(45, 28);
                            cout << ERASE;
                            cout << "\033[25;60H" << COLOR_BACKGROUND_l << WHITE << "   Enter your password: " << RESET;
                            getline(cin, password);
                            // Nếu password trống thì báo lỗi yêu cầu nhập lại
                            bool isLoginPassword = 1;
                            if (password == "")
                            {
                                cout << "\033[27;60H";
                                cout << ERASE;
                                cout << "\033[27;60H" << COLOR_BACKGROUND_g << WHITE << "Password is invalid! Please enter a valid one!" << RESET;
                                isLoginPassword = 0;
                            }
                            // Nếu tên bị trùng thì báo lỗi yêu cầu nhập lại
                            if (isLoginPassword)
                            {
                                if (isPlayed(gameplay, name, password)) {
                                    cout << "\033[27;60H";
                                    cout << ERASE;
                                    cout << "\033[27;60H" << COLOR_BACKGROUND_r << WHITE << "   Login to resume successfully!          " << RESET;
                                    cout << "\033[29;60H" << COLOR_BACKGROUND_i << WHITE << "   Press 'Enter' to continue to play your previous game!  " << RESET;
                                    char enter;
                                    enter = _getch();
                                    system("cls");
                                    continuePrevGame(playerList, gameplay, name, score, password, time, undoStack, redoStack);
                                    return;
                                }
                                else {
                                    cout << "\033[27;60H" << COLOR_BACKGROUND_g << WHITE << "   You have not played any turn before yet!          " << RESET;
                                    cout << "\033[29;60H" << COLOR_BACKGROUND_g << WHITE << "   Press 'Enter' to go back to main menu screen...   " << RESET;
                                    char back = ' ';
                                    backToMenu(back, idx);
                                }
                                break;
                            }
                        }
                    } while (!isPlayed(gameplay, name, password) || password == "" || !isValidName(name));
                }
            }
        }
        // Nhấn mũi tên để di chuyển giữa các chỉ mục
        else {
            arrow = _getch();
            if (arrow == 72) {
                idx = (idx - 1 + 5) % 5;
            }
            else if (arrow == 80) {
                idx = (idx + 1) % 5;
            }
            mainMenuScreen(idx);
        }
    }
}