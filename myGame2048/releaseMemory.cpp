#include"functions.h"

void myListGamePlayer::deletePlayer(string& name)
{
    if (head == NULL)
        return;

    gamePlayer* cur = head;
    gamePlayer* prev = NULL;
    while (cur != NULL)
    {
        if (cur->name == name)
        {
            if (prev != NULL)
            {
                prev->next = cur->next;
            }
            else
            {
                head = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void myListGamePlayer::deleteMemoryList()
{
    while (head != NULL)
    {
        gamePlayer* temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}