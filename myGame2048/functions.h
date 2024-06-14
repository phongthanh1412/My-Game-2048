#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <windows.h>
#include <thread>

// Các mã ANSI ESCAPE CODE để điều chỉnh màu sắc
const char GREEN[] = "\033[32m";
const char MAGENTA[] = "\033[35m";
const char RED[] = "\033[31m";
const char YELLOW[] = "\033[33m";
const char CYAN[] = "\033[36m";
const char BLUE[] = "\033[34m";
const char WHITE[] = "\033[1;37m";
const char BLACK[] = "\033[30m";
const char COLOR_BACKGROUND_BORDER[] = "\033[48;5;246m";
const char COLOR_BACKGROUND_a[] = "\033[48;5;252m";
const char COLOR_BACKGROUND_b[] = "\033[48;5;231m";
const char COLOR_BACKGROUND_c[] = "\033[48;5;230m";
const char COLOR_BACKGROUND_d[] = "\033[48;5;214m";
const char COLOR_BACKGROUND_e[] = "\033[48;5;208m";
const char COLOR_BACKGROUND_f[] = "\033[48;5;203m";
const char COLOR_BACKGROUND_g[] = "\033[48;5;196m";
const char COLOR_BACKGROUND_h[] = "\033[48;5;221m";
const char COLOR_BACKGROUND_i[] = "\033[48;5;21m";
const char COLOR_BACKGROUND_k[] = "\033[48;5;43m";
const char COLOR_BACKGROUND_l[] = "\033[48;5;94m";
const char COLOR_BACKGROUND_m[] = "\033[48;5;102m";
const char COLOR_BACKGROUND_n[] = "\033[48;5;172m";
const char COLOR_BACKGROUND_p[] = "\033[48;5;228m";
const char COLOR_BACKGROUND_q[] = "\033[48;5;196m";
const char COLOR_BACKGROUND_r[] = "\033[48;5;22m";
const char COLOR_BACKGROUND_s[] = "\033[48;5;85m";
const char COLOR_BACKGROUND_u[] = "\033[48;5;210m";
const char COLOR_BACKGROUND_w[] = "\033[48;5;19m";
const char ERASE[] = "\033[2K";
const char RESET[] = "\033[0m";

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

// Khai báo và khởi tạo cấu trúc bảng
struct gamePlay2048
{
    int** table;
    int score = 0;
    int tableSize = 0;
    gamePlay2048();
    gamePlay2048(int size);
};

// Khai báo và khởi tạo cấu trúc 1 nút stack
struct Stack
{
    gamePlay2048 value;
    Stack* next;
    Stack(gamePlay2048 value)
    {
        this->value = value;
        this->next = NULL;
    }
};

// Các hàm thao tác với stack
struct myStack
{
    Stack* head;
    int size;

    myStack() {
        head = NULL;
        size = 0;
    }

    bool isEmptyStack();

    void push(gamePlay2048 value);

    gamePlay2048 pop1();

    gamePlay2048 pop2();

    gamePlay2048 top();

    void deleteMemoryStack();

};

// Khai báo và khởi tạo cấu trúc 1 player
struct gamePlayer
{
    steady_clock::time_point start;
    steady_clock::time_point end;
    string name, password;
    int score;
    float timeLapse;
    gamePlayer* next;
    gamePlayer(string name, string password, int score, float timeLapse)
    {
        this->name = name;
        this->password = password;
        this->score = score;
        this->timeLapse = timeLapse;
        this->next = NULL;
    }
};

// Các hàm thao tác với danh sách player
struct myListGamePlayer
{
    gamePlayer* head;

    myListGamePlayer() {
        head = NULL;
    }

    void addPlayer(gamePlayer* newpPlayer);

    void sortPlayersByTime();

    void deletePlayer(string& name);

    void writeToFile();

    void showTop_20List();

    void deleteMemoryList();

};

// Hàm restart game
void restartNewGame(gamePlay2048& gameplay, int& scores, myStack& undoStack, int**& pseudo_table, int tableSize);

// Hàm kiểm tra tên đăng nhập đã tồn tại hay chưa
bool isExistInfo(gamePlay2048& gameplay, string& name, string& password, int& score);

// Hàm kiểm tra ký tự hợp lệ
bool isValidChar(char c);

// Hàm kiểm tra tên hợp lệ
bool isValidName(string name);

// Hàm kiểm tra nguời chơi đã chơi ít nhất 1 lượt nào hay chưa
bool isPlayed(gamePlay2048& gameplay, string& name, string& password);

// Hàm ghi thông tin người mới vừa chơi vào file binary
void updatePlayer(myListGamePlayer& playerList, string& name, string& password, gamePlay2048& gameplay, float& timeLapse);

// Hàm đọc file binary đã ghi trước đó và so sánh với thông tin người chơi hiện tại để cập nhật lại danh sách
void updatePlayerListFromFile(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name);

// Hàm lưu trạng thái trò chơi để backup cho lần chơi sau nếu muốn tiếp tục chơi ván trước
void saveGame(gamePlay2048& gameplay, string& password, gamePlayer*& player, string& name, float& timeLapse, myStack& undoStack, myStack& redoStack);

// Hàm tiếp tục chơi lại ván trước 
void continuePrevGame(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name, int& scores, string& password, float& timeLapse, myStack& undoStack, myStack& redoStack);

// Màn hình chiến thắng
void winGameScreen();

// Màn hình thua game
void gameOverScreen();

// Màn hình kết thúc
void sayThanks();

// Hàm tổng hợp toàn bộ các thao tác trò chơi
void GamePlayProcess();