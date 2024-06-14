#include"functions.h"
#include"prepareForGame.h"

bool isPlayed(gamePlay2048& gameplay, string& name, string& password) {
    fstream ifile;
    ifile.open("list_top20_players.bin", ios::in | ios::binary);
    if (ifile.eof())
    {
        return 0;
    }
    while (!ifile.eof())
    {
        // Đọc tên người chơi
        string existName;
        char c;
        while (ifile.get(c) && c != '\0')
        {
            existName += c;
        }
        // Kiểm tra nếu gặp EOF hoặc lỗi đọc
        if (ifile.eof() || ifile.fail())
        {
            break;
        }
        // Đọc điểm số
        int scores;
        ifile.read((char*)&scores, sizeof(scores));
        if (ifile.eof() || ifile.fail())
        {
            break;
        }
        // Đọc mật khẩu
        string existpassword;
        while (ifile.get(c) && c != '\0')
        {
            existpassword += c;
        }
        // Kiểm tra nếu gặp EOF hoặc lỗi đọc
        if (ifile.eof() || ifile.fail())
        {
            break;
        }
        // Đọc thời gian trôi qua
        float timeLapse;
        ifile.read((char*)&timeLapse, sizeof(timeLapse));
        if (ifile.eof() || ifile.fail())
        {
            break;
        }
        if (name == existName && password == existpassword)
        {
            ifile.close();
            return 1;
        }
    }

    ifile.close();
    return 0;
}
