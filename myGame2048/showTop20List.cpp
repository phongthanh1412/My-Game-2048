#include "functions.h"
#include "prepareForGame.h"

void myListGamePlayer::showTop_20List()
{
    fstream ofile;
    ofile.open("list_top20_players.bin", ios::out | ios::binary);
    if (!ofile.is_open())
    {
        return;
    }
    gotoxy(43, 2);
    cout << "     _____              ____   ___          _                                  " << endl;
    gotoxy(43, 3);
    cout << "    /__   \\___  _ __   |___ \\ / _ \\   _ __ | | __ _ _   _  ___ _ __ ___     " << endl;
    gotoxy(43, 4);
    cout << "      / /\\/ _ \\| '_ \\    __) | | | | | '_ \\| |/ _` | | | |/ _ \\ '__/ __|  " << endl;
    gotoxy(43, 5);
    cout << "     / / | (_) | |_) |  / __/| |_| | | |_) | | (_| | |_| |  __/ |  \\__ \\     " << endl;
    gotoxy(43, 6);
    cout << "      \\/   \\___/| .__/  |_____\\___/  | .__/|_|\\__,_|\\__, |\\___|_|  |___/  " << endl;
    gotoxy(43, 7);
    cout << "               |_|                   |_|            |___/                      " << endl;
    // Vẽ bảng xếp hạng lên màn hình
    gotoxy(58, 10);
    cout << COLOR_BACKGROUND_l << "                                               " << RESET << endl;
    gotoxy(58, 11);
    cout << COLOR_BACKGROUND_l << "  " << COLOR_BACKGROUND_c << BLUE << "    Player    " << COLOR_BACKGROUND_l << "  "
         << COLOR_BACKGROUND_c << "    Score   " << COLOR_BACKGROUND_l << "  "
         << COLOR_BACKGROUND_c << "    Time     " << COLOR_BACKGROUND_l << "  " << RESET << endl;
    gotoxy(58, 12);
    cout << COLOR_BACKGROUND_l << "                                               " << RESET << endl;

    // Ghi bảng xếp hạng vào file.bin
    gamePlayer* temp = head;
    int row = 13;
    while (temp != NULL)
    {
        ofile.write(temp->name.c_str(), temp->name.size() + 1);
        ofile.write((char*)&temp->score, sizeof(temp->score));
        ofile.write(temp->password.c_str(), temp->password.size() + 1);
        ofile.write((char*)&temp->timeLapse, sizeof(temp->timeLapse));

        // Xuất bảng xếp hạng ra màn hình console
        gotoxy(58, row);
        cout << COLOR_BACKGROUND_l << "  "
             << COLOR_BACKGROUND_c << BLACK << setw(14) << left << temp->name << RESET << COLOR_BACKGROUND_c << "  "
             << COLOR_BACKGROUND_c << BLACK << setw(12) << right << temp->score << RESET << COLOR_BACKGROUND_c << "  "
             << COLOR_BACKGROUND_c << BLACK << fixed << setprecision(5) << setw(13) << right << temp->timeLapse << RESET << COLOR_BACKGROUND_l << "  " << RESET << endl;

        // Tiếp tục đến người chơi tiếp theo và xuống dòng trong bảng
        temp = temp->next;
        row += 1;
    }

    // Vẽ đường viền cuối cùng của bảng
    gotoxy(58, row);
    cout << COLOR_BACKGROUND_l << "                                               " << RESET << endl;

    ofile.close();
}
