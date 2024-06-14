#include"functions.h"

bool isExistInfo(gamePlay2048& gameplay, string& name, string& password, int& score)
{
    fstream ifile("list_top20_players.bin", ios::in | ios::binary);
    if (!ifile.is_open())
    {
        return 0;
    }
    while (true)
    {
        // Đọc tên người chơi
        string existname;
        char c;
        while (ifile.get(c) && c != '\0')
        {
            existname += c;
        }
        // Kiểm tra nếu gặp EOF hoặc lỗi đọc
        if (ifile.eof() || ifile.fail())
        {
            break;
        }
        // Đọc điêm người chơi
        int existscores;
        ifile.read((char*)&existscores, sizeof(existscores));
        // Kiểm tra nếu gặp EOF hoặc lỗi đọc
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
        float timeLapse;
        ifile.read((char*)&timeLapse, sizeof(timeLapse));
        // Kiểm tra nếu gặp EOF hoặc lỗi đọc
        if (ifile.eof() || ifile.fail())
        {
            break;
        }
        // Nếu tên người dùng giống nhưng mật khẩu khác thì lỗi trùng tên
        if (name == existname)
        {
            ifile.close();
            return 1;
        }       
    }
    ifile.close();
    return 0;
}