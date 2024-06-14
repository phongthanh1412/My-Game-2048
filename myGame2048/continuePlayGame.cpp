#include "functions.h"

void saveGame(gamePlay2048& gameplay, string& password, gamePlayer*& player, string& name, float& timeLapse, myStack& undoStack, myStack& redoStack) {
    fstream ofile;
    string filename = "_information.bin";
    ofile.open(filename, ios::out | ios::binary);
    if (ofile.eof()) {
        return;
    }
    for (int i = 0; i < gameplay.tableSize; i++) {
        for (int j = 0; j < gameplay.tableSize; j++) {
            ofile.write((char*)&gameplay.table[i][j], sizeof(gameplay.table[i][j]));
        }
    }
    // Lưu thông tin người chơi
    ofile.write(name.c_str(), name.size() + 1);
    ofile.write((char*)&player->score, sizeof(player->score));
    ofile.write(password.c_str(), password.size() + 1);
    ofile.write((char*)&timeLapse, sizeof(timeLapse));

    ofile.close();
}

void continuePrevGame(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name, int& scores, string& password, float& timeLapse, myStack& undoStack, myStack& redoStack) {
    fstream ifile;
    string filename = "_information.bin";
    ifile.open(filename, ios::in | ios::binary);
    if (ifile.eof()) {
        return;
    }

    for (int i = 0; i < gameplay.tableSize; i++) {
        for (int j = 0; j < gameplay.tableSize; j++) {
            ifile.read((char*)&gameplay.table[i][j], sizeof(gameplay.table[i][j]));
        }
    }
    string playerName;
    char c;
    while (ifile.get(c) && c != '\0') {
        playerName += c;
    }
    // Kiểm tra nếu gặp EOF hoặc lỗi đọc
    if (ifile.eof() || ifile.fail()) {
        return;
    }

    // Đọc điểm số
    int score;
    ifile.read((char*)&score, sizeof(score));
    if (ifile.eof() || ifile.fail()) {
        return;
    }

    // Đọc mật khẩu
    string existpassword;
    while (ifile.get(c) && c != '\0') {
        existpassword += c;
    }
    // Kiểm tra nếu gặp EOF hoặc lỗi đọc
    if (ifile.eof() || ifile.fail()) {
        return;
    }

    // Đọc thời gian trôi qua
    float timeLapses;
    ifile.read((char*)&timeLapses, sizeof(timeLapses));
    if (ifile.eof() || ifile.fail()) {
        return;
    }

    ifile.close();
}
