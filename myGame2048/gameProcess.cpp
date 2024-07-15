#include"functions.h"
#include"prepareForGame.h"
#include"gameLogic.h"
#include"undo_redo.h"

using namespace std;

gamePlay2048::gamePlay2048()
{
    // Tạo constructor
    int tableSize = 0;
    table = new int* [tableSize];
    for (int i = 0; i < tableSize; i++)
        table[i] = new int[tableSize];
    for (int i = 0; i < tableSize; i++)
        for (int j = 0; j < tableSize; j++)
            table[i][j] = 0;
}
gamePlay2048::gamePlay2048(int size) {
    tableSize = size;
    table = new int* [tableSize];
    for (int i = 0; i < tableSize; ++i) {
        table[i] = new int[tableSize];
        for (int j = 0; j < tableSize; ++j) {
            table[i][j] = 0;
        }
    }
}
void GamePlayProcess()
{
    // Khai báo
    myListGamePlayer playerList;
    gamePlay2048 gameplay;
    myStack undoStack, redoStack;
    string name, password;
    float timeLapse;
    int scores = 0, tableSize = 4;
    bool canUndo = 0, canRedo = 0;
    int x = 0, y = 0;
    int** pseudo_table = NULL;
    int countWin = 0;

    // Bắt đầu thực hiện trò chơi
    updatePlayerListFromFile(playerList, gameplay, name);
    menuIntroduce(playerList, gameplay, name, password, scores, canUndo, canRedo, timeLapse, tableSize);
    steady_clock::time_point startTime = steady_clock::now(); // Đo thời gian lúc bắt đầu chơi
    pushToUndoStack(gameplay, undoStack, tableSize); // Đẩy trạng thái trò chơi vào stack
    
    while (1)
    {
        char key;
        display_menu(gameplay, name, x, y, tableSize);
        if (canUndo && !canRedo) {
            gotoxy(37, 8);
            cout << COLOR_BACKGROUND_r << setw(16) << " " << RESET << endl;
            gotoxy(37, 9);
            cout << COLOR_BACKGROUND_r << "  " << COLOR_BACKGROUND_r << WHITE << setw(10) << left << "Undo mode   " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(37, 10);
            cout << COLOR_BACKGROUND_r << "  " << COLOR_BACKGROUND_r << WHITE << setw(10) << left << "is turned on" << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(37, 11);
            cout << COLOR_BACKGROUND_r << setw(16) << " " << RESET << endl;
        }
        else if (canUndo && canRedo) {
            gotoxy(37, 8);
            cout << COLOR_BACKGROUND_r << setw(19) << " " << RESET << endl;
            gotoxy(37, 9);
            cout << COLOR_BACKGROUND_r << "  " << COLOR_BACKGROUND_r << WHITE << setw(10) << left << "Undo/Redo mode " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(37, 10);
            cout << COLOR_BACKGROUND_r << "  " << COLOR_BACKGROUND_r << WHITE << setw(10) << left << "is turned on   " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(37, 11);
            cout << COLOR_BACKGROUND_r << setw(19) << " " << RESET << endl;
        }
        else {
            gotoxy(37, 8);
            cout << COLOR_BACKGROUND_g << setw(19) << " " << RESET << endl;
            gotoxy(37, 9);
            cout << COLOR_BACKGROUND_g << "  " << COLOR_BACKGROUND_g << WHITE << setw(10) << left << "Undo/Redo mode " << COLOR_BACKGROUND_g << "  " << RESET << endl;
            gotoxy(37, 10);
            cout << COLOR_BACKGROUND_g << "  " << COLOR_BACKGROUND_g << WHITE << setw(10) << left << "is turned off  " << COLOR_BACKGROUND_g << "  " << RESET << endl;
            gotoxy(37, 11);
            cout << COLOR_BACKGROUND_g << setw(19) << " " << RESET << endl;
        }

        if (isWinGame(gameplay, tableSize))
        {
            countWin++;
            steady_clock::time_point endTime = steady_clock::now(); // Đo thời gian lúc kết thúc chơi
            duration<float> elapsedTime = endTime - startTime;      // Khoảng thời gian tính được
            timeLapse = elapsedTime.count();

            // Đảm bảo người chơi chỉ thắng 1 lần và chơi đến khi thua hoặc nhấn exit
            if (isWinGame(gameplay, tableSize) && countWin <= 1) {
                winGameScreen();
            }
            display_menu(gameplay, name, x, y, tableSize);
            updatePlayer(playerList, name, password, gameplay, timeLapse); // Cập nhật danh sách vào file.bin
            gotoxy(43, 31);
            cout << COLOR_BACKGROUND_r << setw(85) << " " << RESET << endl;
            gotoxy(43, 32);
            cout << COLOR_BACKGROUND_r << "  " << WHITE << setw(10) << left << "            C O N G R A T U L A T I O N S!   Y O U   W I N !                     " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(43, 33);
            cout << COLOR_BACKGROUND_r << "  " << WHITE << setw(10) << left << "            > Press 'control key' to continue to play game...                    " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(43, 34);
            cout << COLOR_BACKGROUND_r << "  " << WHITE << setw(10) << left << "                  >  Press 'e' to exit the game...                               " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(43, 35);
            cout << COLOR_BACKGROUND_r << setw(85) << " " << RESET << endl;
        }
        if (isGameOver(gameplay, tableSize))
        {
            steady_clock::time_point endTime = steady_clock::now(); // Đo thời gian lúc kết thúc chơi
            duration<float> elapsedTime = endTime - startTime;      // Khoảng thời gian tính được
            timeLapse = elapsedTime.count();
            gameOverScreen();
            display_menu(gameplay, name, x, y, tableSize);
            updatePlayer(playerList, name, password, gameplay, timeLapse); // Cập nhật danh sách vào file.bin           
            //Sau khi chơi xong thì giải phóng bộ nhớ trạng thái undo và redo của từng người chơi
            redoStack.deleteMemoryStack();
            undoStack.deleteMemoryStack();
            gotoxy(50, 37);
            cout << COLOR_BACKGROUND_i << setw(74) << " " << RESET << endl;
            gotoxy(50, 38);
            cout << COLOR_BACKGROUND_i << "  " << WHITE << setw(10) << left << "   Thanks for playing! Press 'Enter' to go back to main menu screen   " << COLOR_BACKGROUND_i << "  " << RESET << endl;
            gotoxy(50, 39);
            cout << COLOR_BACKGROUND_i << setw(74) << " " << RESET << endl;
            break;
        }
        key = _getch();
        if (key == 13) {
            system("cls");
            prepareForGame(playerList, gameplay, name, password, scores, canUndo, canRedo, timeLapse, tableSize);
            startTime = steady_clock::now();
        }
        if (key == 'n') // restart game
        {
            undoStack.deleteMemoryStack();
            restartNewGame(gameplay, scores, undoStack, pseudo_table, tableSize);
        }
        else if (key == 'u' && canUndo) // undo
        {
            undoTable(gameplay, undoStack, redoStack, tableSize);
        }
        else if (key == 'u' && !canUndo) // undo
        {
            gotoxy(60, 14);
            cout << COLOR_BACKGROUND_g << WHITE << "                                                " << RESET << endl;
            gotoxy(60, 15);
            cout << COLOR_BACKGROUND_g << WHITE << "          Undo mode is turned off               " << RESET << endl;
            gotoxy(60, 16);
            cout << COLOR_BACKGROUND_g << WHITE << "  You can not undo the previous state of game   " << RESET << endl;
            gotoxy(60, 17);
            cout << COLOR_BACKGROUND_g << WHITE << "                                                " << RESET << endl;
        }

        else if (key == 'r' && canUndo && canRedo) // redo
        {
            redoTable(gameplay, undoStack, redoStack, tableSize);
        }
        else if (key == 'r' && (!canUndo || !canRedo)) // redo
        {
            gotoxy(60, 14); 
            cout << COLOR_BACKGROUND_g << WHITE << "                                                     " << RESET << endl;
            gotoxy(60, 15);
            cout << COLOR_BACKGROUND_g << WHITE << "              Redo mode is turned off                " << RESET << endl;
            gotoxy(60, 16);
            cout << COLOR_BACKGROUND_g << WHITE << "  You can not redo the previous state of game        " << RESET << endl;
            gotoxy(60, 17);
            cout << COLOR_BACKGROUND_g << WHITE << "                                                     " << RESET << endl;
        }

        else if (key == 'e') // Exit
        {
            char noti;
            gotoxy(60, 14);
            cout << COLOR_BACKGROUND_g << WHITE << "                                                " << RESET << endl;
            gotoxy(60, 15);
            cout << COLOR_BACKGROUND_g << WHITE << " Are you sure you want to exit the game? (y/n)? " << RESET << endl;
            gotoxy(60, 16);
            cout << COLOR_BACKGROUND_g << WHITE << " --> Press 'n' if No/ 'y' if Yes!               " << RESET << endl;
            gotoxy(60, 17);
            cout << COLOR_BACKGROUND_g << WHITE << "                                                " << RESET << endl;
            noti = _getch();
            // Nhấn 'n' sau khi nhấn 'e' thì tiếp tục chơi tiếp, nhấn 'y' thì thoát
            if (noti == 'n') {
                gotoxy(54, 14);
                cout << ERASE;
                gotoxy(54, 15);
                cout << ERASE;
                gotoxy(54, 16);
                cout << ERASE;
                gotoxy(54, 17);
                cout << ERASE;
                continue;
            }
            else
            {
                scores = gameplay.score;
                steady_clock::time_point endTime = steady_clock::now(); // Đo thời gian lúc kết thúc chơi
                duration<float> elapsedTime = endTime - startTime;      // Khoảng thời gian tính được
                timeLapse = elapsedTime.count();
                updatePlayer(playerList, name, password, gameplay, timeLapse); // Cập nhật danh sách vào file.bin                               
                //Sau khi chơi xong thì giải phóng bộ nhớ trạng thái undo và redo của từng người chơi
                redoStack.deleteMemoryStack();
                undoStack.deleteMemoryStack();
                gotoxy(50, 37);
                cout << COLOR_BACKGROUND_i << setw(74) << " " << RESET << endl;
                gotoxy(50, 38);
                cout << COLOR_BACKGROUND_i << "  " << COLOR_BACKGROUND_i << WHITE << setw(10) << left << "   Thanks for playing! Press 'Enter' to go back to main menu screen   " << COLOR_BACKGROUND_i << "  " << RESET << endl;
                gotoxy(50, 39);
                cout << COLOR_BACKGROUND_i << setw(74) << " " << RESET << endl;
                char enter;
                do {
                    enter = _getch();
                } while (enter != 13);
                if (enter == 13) {
                    sayThanks();
                    char button;
                    do {
                        button = _getch();
                    } while (button != 13 && button != 'e');
                    if (button == 13) {
                        system("cls");
                        countWin = 0;
                        prepareForGame(playerList, gameplay, name, password, scores, canUndo, canRedo, timeLapse, tableSize); // Hiện menu và chuẩn bị thao tác nhập
                        startTime = steady_clock::now();
                    }
                    else break;
                }
            }
        }
        else
        {
            make_pseudo_table(gameplay, pseudo_table, tableSize); // Tạo bảng giả để lưu các giá trị thay đổi lẫn không thay đổi
            
            cout << ERASE;
            // Các phím di chuyển lên, xuống, trái, phải
            if (key == 'w')
                moveUp(gameplay, tableSize);
            else if (key == 's')
                moveDown(gameplay, tableSize);
            else if (key == 'a')
                moveLeft(gameplay, tableSize);
            else if (key == 'd')
                moveRight(gameplay, tableSize);
            if (!isChangetable(gameplay, pseudo_table, tableSize))
            {
                continue;
            }
            else
            {
                init_new_number(gameplay, tableSize);
                pushToUndoStack(gameplay, undoStack, tableSize);               
            }
            // Đảm bảo rằng không có bất kỳ thao tác nào chèn giữa undo và redo
            redoStack.deleteMemoryStack();
        }
        if (key == 'n')
        {
            undoStack.deleteMemoryStack();
            restartNewGame(gameplay, scores, undoStack, pseudo_table, tableSize);
        }
    }
    
    // Giải phóng bộ nhớ cho danh sách người chơi
    playerList.deleteMemoryList();

    //Giải phóng bộ nhớ cho bảng game 2048
    if (pseudo_table != NULL) {
        for (int i = 0; i < tableSize; i++) {
            delete[] pseudo_table[i];
        }
        delete[] pseudo_table;
        pseudo_table = NULL;
    }

    for (int i = 0; i < tableSize; i++)
        delete[] gameplay.table[i];
    delete[] gameplay.table;
    gameplay.table = NULL;
}
