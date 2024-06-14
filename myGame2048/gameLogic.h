#pragma once

#include"functions.h"

// Hàm hiển thị màn hình giao diện trò chơi
void display_menu(gamePlay2048& gameplay, string& name, int x, int y, int tableSize);

// Hàm tạo bảng trò chơi
void init_table(gamePlay2048& gameplay, int tableSize);

// Hàm tạo ngẫu nhiên thêm một số 2 hoặc 4 sau mỗi bước di chuyển hợp lệ, tuỳ theo tỉ lệ 80/20
void init_new_number(gamePlay2048 gameplay, int tableSize);

// Hàm di chuyển các ô lên trên
void moveUp(gamePlay2048& gameplay, int tableSize);

// Hàm di chuyển các ô xuống dưới
void moveDown(gamePlay2048& gameplay, int tableSize);

// Hàm di chuyển các ô sang trái
void moveLeft(gamePlay2048& gameplay, int tableSize);

// Hàm di chuyển các ô sang phải
void moveRight(gamePlay2048& gameplay, int tableSize);

// Hàm kiểm tra xem đã đạt 2048 điểm chưa để thắng game
bool isWinGame(gamePlay2048 gameplay, int tableSize);

// Hàm kiểm tra các phần tử có bằng 0 hay không
bool isZerotable(gamePlay2048 gameplay, int tableSize);

// Hàm kiểm tra trò chơi kết thúc hay chưa
bool isGameOver(gamePlay2048 gameplay, int tableSize);

void make_pseudo_table(gamePlay2048& gameplay, int**& pseudo_table, int tableSize);
// Kiểm tra xem bảng có thay đổi hay không bằng cách so sánh với bảng "giả" đã tạo

//Kiểm tra xem bảng có thay đổi không 
bool isChangetable(gamePlay2048 gameplay, int**& pseudo_table, int tableSize);