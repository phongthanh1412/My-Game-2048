#include"functions.h"
#include"gameLogic.h"

bool isWinGame(gamePlay2048 gameplay, int tableSize)
{
    for (int i = 0; i < tableSize; i++)
    {
        for (int j = 0; j < tableSize; j++)
        {
            if (gameplay.table[i][j] == 2048)
                return 1;
        }
    }
    return 0;
}