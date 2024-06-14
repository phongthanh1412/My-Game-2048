#include"functions.h"

void updatePlayer(myListGamePlayer& playerList, string& name, string& password, gamePlay2048& gameplay, float& timeLapse)
{
    gamePlayer* player = new gamePlayer(name, password, gameplay.score, timeLapse);
    playerList.addPlayer(player);
    playerList.writeToFile();
}

void updatePlayerListFromFile(myListGamePlayer& playerList, gamePlay2048& gameplay, string& name)
{
    fstream ifile("list_top20_players.bin", ios::in | ios::binary);
    if (ifile.eof())
    {
        return;
    }
    while (1)
    {
        // Đọc tên người chơi
        string playerName;
        char c;
        while (ifile.get(c) && c != '\0')
        {
            playerName += c;
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
        string password;
        while (ifile.get(c) && c != '\0')
        {
            password += c;
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
        // Xoá tên trùng để cập nhật thông tin mới
        if (name == playerName)
        {
            playerList.deletePlayer(playerName);
        }
        // Thêm người chơi vào danh sách nếu đạt điểm số yêu cầu
        if (scores >= gameplay.score)
        {
            gamePlayer* player = new gamePlayer(playerName, password, scores, timeLapse);
            playerList.addPlayer(player);
        }
    }
    ifile.close();
}