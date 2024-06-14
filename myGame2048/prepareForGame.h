#pragma once

#include"functions.h"

// Hàm xác định toạ độ các dòng chữ, bảng
void gotoxy(int x, int y);

// Hàm vẽ màu sắc
void printWithColor(const string& color, const string& text);

// Tô màu toàn màn hình
void colorScreen(const string& color, int time);

// Hàm quay về màn hình chính
void backToMenu(char back, int idx);

// Hàm hiện màn hình giới thiệu game
void menuIntroduce(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name, string& password, int& score, bool& canUndo, bool& canRedo, float& time, int& tableSize);

// Hàm hiện màn hình chính
void mainMenuScreen(int idx);

// Hàm hiện màn hình cài đặt
void menuSetting(int idx);

// Hàm hiện màn hình đăng nhập
void menuLogin();

// Hàm hướng dẫn luật chơi và cách di chuyển
void tutorial();

//Hàm hiện màn hình resume
void menuResume();

// Hàm đăng nhập tên, xem hướng dẫn chơi game, các luật trước khi bắt đầu chơi
void prepareForGame(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name, string& password, int& score, bool& canUndo, bool& canRedo, float& time, int& tableSize);



