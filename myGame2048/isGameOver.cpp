#include"functions.h"
#include"gameLogic.h"

bool isGameOver(gamePlay2048 gameplay, int tableSize)
{
    if (isZerotable(gameplay, tableSize))
        return 0;
    // Kiểm tra các cặp ngang
    for (int i = 0; i < tableSize; i++)
    {
        for (int j = 0; j < tableSize - 1; j++)
        {
            if (gameplay.table[i][j] == gameplay.table[i][j + 1])
                return 0;
        }
    }
    // Kiểm tra các cặp dọc
    for (int i = 0; i < tableSize - 1; i++)
    {
        for (int j = 0; j < tableSize; j++)
        {
            if (gameplay.table[i][j] == gameplay.table[i + 1][j])
                return 0;
        }
    }
    return 1;
}