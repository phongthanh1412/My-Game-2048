#include"functions.h"

void GamePlayProcess()
{
    // Khai báo
    int** pseudo_table = new int* [tableSize];
    myStack undoStack, redoStack;
    myListGamePlayer playerList;
    gamePlay2048 gameplay;
    int scores = 0;
    string name, password;
    float timeLapse;

    // Bắt đầu thực hiện trò chơi
    updatePlayerListFromFile(playerList, gameplay, name);
    prepareForGame(gameplay, name, password, scores);  // Hiện menu và chuẩn bị thao tác nhập
    steady_clock::time_point startTime = steady_clock::now(); // Đo thời gian lúc bắt đầu chơi
    pushToUndoStack(gameplay, undoStack);// Đẩy trạng thái trò chơi vào stack

    while (1)
    {
        char key;
        clearScreen();
        display_menu(gameplay, name);
        if (isWinGame(gameplay))
        {
            cout << "\033[31;60H" << GREEN << "CONGRATULATIONS! YOU WIN THE GAME! PRESS ANY KEY TO GO BACK TO MENU...\n" << RESET;
            steady_clock::time_point endTime = steady_clock::now(); // Đo thời gian lúc kết thúc chơi
            duration<float> elapsedTime = endTime - startTime; // Khoảng thời gian tính được
            timeLapse = elapsedTime.count();
            updatePlayer(playerList, name, password, gameplay, timeLapse);// Cập nhật danh sách vào file.txt
            break;
        }
        if (isGameOver(gameplay))
        {
            cout << "\033[31;60H" << RED << "GAME OVER! PRESS ANY KEY TO GO BACK TO MENU...\n" << RESET;
            steady_clock::time_point endTime = steady_clock::now(); // Đo thời gian lúc kết thúc chơi
            duration<float> elapsedTime = endTime - startTime; // Khoảng thời gian tính được
            timeLapse = elapsedTime.count();
            updatePlayer(playerList, name, password, gameplay, timeLapse);// Cập nhật danh sách vào file.txt
            break;
        }
        key = _getch();
        if (key == 'r')      // restart game
        {
            undoStack.deleteMemoryStack();
            restartNewGame(gameplay, scores, undoStack, pseudo_table);
        }
        else if (key == 'u') //undo
        {
            undoTable(gameplay, undoStack, redoStack);
        }
        else if (key == 'l') //redo
        {
            redoTable(gameplay, undoStack, redoStack);
        }
        else if (key == 'q') //quit
        {
            char noti;
            cout << "\033[9;60H" << RED << "Are you sure you want to quit the game? (y/n)?" << RESET;
            cout << "\033[11;60H" << RED << "--> Press 'n' if No/ 'y' if Yes!\n" << RESET;
            noti = _getch();
            if (noti == 'n')// Nhấn 'n' sau khi nhấn 'q' thì tiếp tục chơi tiếp, nhấn 'y' thì thoát
                continue;
            else
            {
                scores = gameplay.score;
                steady_clock::time_point endTime = steady_clock::now(); // Đo thời gian lúc kết thúc chơi
                duration<float> elapsedTime = endTime - startTime; // Khoảng thời gian tính được
                timeLapse = elapsedTime.count();
                updatePlayer(playerList, name, password, gameplay, timeLapse); // Cập nhật danh sách vào file.txt
                cout << "\033[31;60H" << BLUE << "Thanks for playing! Press any key to go back to menu..." << RESET;
                char key2;
                key2 = _getch();

                prepareForGame(gameplay, name, password, scores); // Hiện menu và chuẩn bị thao tác nhập
                startTime = steady_clock::now();
            }
        }
        else
        {
            make_pseudo_table(gameplay, pseudo_table);// Tạo bảng giả để lưu các giá trị thay đổi lẫn không thay đổi
            // Các phím di chuyển lên, xuống, trái, phải
            if (key == 72)
                moveUp(gameplay);
            else if (key == 80)
                moveDown(gameplay);
            else if (key == 75)
                moveLeft(gameplay);
            else if (key == 77)
                moveRight(gameplay);
            if (!isChangetable(gameplay, pseudo_table))
            {
                continue;
            }
            else
            {
                init_new_number(gameplay);
                pushToUndoStack(gameplay, undoStack);
            }
            // Đảm bảo rằng không có bất kỳ thao tác nào chèn giữa undo và redo
            redoStack.deleteMemoryStack();
        }
        if (key == 'r')
        {
            undoStack.deleteMemoryStack();
            restartNewGame(gameplay, scores, undoStack, pseudo_table);
        }
    }

    // Lưu kết quả riêng của từng người chơi vào file riêng
    gamePlayer* cur = playerList.head;
    while (cur != NULL) {
        saveGame(gameplay, password, cur);
        cur = cur->next; // Di chuyển đến người chơi tiếp theo trong danh sách để có thể ghi nhiều file thông tin
    }

    // Giải phóng bộ nhớ 
    playerList.deleteMemoryList();

    for (int i = 0; i < tableSize; i++)
        delete[] pseudo_table[i];
    delete[] pseudo_table;

    for (int i = 0; i < tableSize; i++)
        delete[] gameplay.table[i];
    delete[] gameplay.table;
}