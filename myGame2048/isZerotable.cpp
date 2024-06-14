#include"functions.h"

bool isZerotable(gamePlay2048 gameplay, int tableSize)
{
    for (int i = 0; i < tableSize; i++)
    {
        for (int j = 0; j < tableSize; j++)
        {
            if (gameplay.table[i][j] == 0)
                return 1;
        }
    }
    return 0;
}