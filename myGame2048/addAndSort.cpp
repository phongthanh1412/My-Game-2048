#include"functions.h"

void myListGamePlayer::sortPlayersByTime()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    bool sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        gamePlayer* cur = head;
        gamePlayer* prev = NULL;
        // Nếu điểm bằng nhau thì so sánh thời gian chơi để xếp hạng
        while (cur->next != NULL)
        {
            if (cur->score == cur->next->score && cur->timeLapse > cur->next->timeLapse)
            {
                if (prev != NULL)
                    prev->next = cur->next;
                else
                    head = cur->next;

                gamePlayer* temp = cur->next->next;
                cur->next->next = cur;
                cur->next = temp;

                sorted = 0;
                if (prev == NULL)
                    cur = head;
                else
                    cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = cur->next; // Di chuyển biến cur đến khi tìm thấy điểm trùng nhau
            }
        }
    }
}

void myListGamePlayer::addPlayer(gamePlayer* newpPlayer)
{
    if (head == NULL)
    {
        head = newpPlayer;
    }
    else
    {
        // Xoá dữ liệu người chơi cũ nếu có tên trùng (tức có người chơi lại thì xoá thông tin cũ)
        deletePlayer(newpPlayer->name);

        // Thêm người chơi vào danh sách
        gamePlayer* cur = head;
        if (head == NULL)
        {
            head = newpPlayer;
        }
        else
        {
            if (newpPlayer->score > head->score)
            {
                newpPlayer->next = head;
                head = newpPlayer;
            }
            else
            {
                gamePlayer* temp = head;
                while (temp->next != NULL && newpPlayer->score < temp->next->score)
                {
                    temp = temp->next;
                }
                newpPlayer->next = temp->next;
                temp->next = newpPlayer;
            }
        }
        // Xếp thứ hạng theo thời gian nếu có 2 người chơi bằng điểm nhau
        sortPlayersByTime();
    }
    // Giới hạn lưu top 10 người chơi cao điểm nhất
    gamePlayer* cur = head;
    int size = 1;
    while (cur->next != NULL && size < 20) {
        cur = cur->next;
        size++;
    }
    if (size >= 20) {
        gamePlayer* temp = cur->next;
        cur->next = NULL;
        delete temp;
    }
}