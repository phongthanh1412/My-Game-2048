#include "functions.h"
#include "prepareForGame.h"

void myListGamePlayer::writeToFile()
{
    fstream ofile;
    ofile.open("list_top20_players.bin", ios::out | ios::binary);
    if (!ofile.is_open())
    {
        return;
    }

    // Vẽ bảng xếp hạng lên màn hình
    gotoxy(117, 1);
    cout << COLOR_BACKGROUND_l << "                                               " << RESET << endl;
    gotoxy(117, 2);
    cout << COLOR_BACKGROUND_l << "  " << COLOR_BACKGROUND_c << BLUE << "    Player    " << COLOR_BACKGROUND_l << "  "
        << COLOR_BACKGROUND_c << "    Score   " << COLOR_BACKGROUND_l << "  "
        << COLOR_BACKGROUND_c << "    Time     " << COLOR_BACKGROUND_l << "  " << RESET << endl;
    gotoxy(117, 3);
    cout << COLOR_BACKGROUND_l << "                                               " << RESET << endl;
    
    // Ghi bảng xếp hạng vào file.bin
    gamePlayer* temp = head;
    int row = 4;
    while (temp != NULL)
    {
        ofile.write(temp->name.c_str(), temp->name.size() + 1);
        ofile.write((char*)&temp->score, sizeof(temp->score));
        ofile.write(temp->password.c_str(), temp->password.size() + 1);
        ofile.write((char*)&temp->timeLapse, sizeof(temp->timeLapse));

        // Xuất bảng xếp hạng ra màn hình console
        gotoxy(117, row);
        cout << COLOR_BACKGROUND_l << "  "
             << COLOR_BACKGROUND_c << BLACK << setw(14) << left << temp->name << RESET << COLOR_BACKGROUND_c << "  "
             << COLOR_BACKGROUND_c << BLACK << setw(12) << right << temp->score << RESET << COLOR_BACKGROUND_c << "  "
             << COLOR_BACKGROUND_c << BLACK << fixed << setprecision(5) << setw(13) << right << temp->timeLapse << RESET << COLOR_BACKGROUND_l << "  " << RESET << endl;

        // Tiếp tục đến người chơi tiếp theo và xuống dòng trong bảng
        temp = temp->next;
        row += 1;
    }

    // Vẽ đường viền cuối cùng của bảng
    gotoxy(117, row);
    cout << COLOR_BACKGROUND_l << "                                               " << RESET << endl;

    ofile.close();
}
