#include"functions.h"
#include"gameLogic.h"

void init_table(gamePlay2048& gameplay, int tableSize)
{
    // Khởi tạo bảng
    gameplay.table = new int* [tableSize];
    for (int i = 0; i < tableSize; ++i)
    {
        gameplay.table[i] = new int[tableSize];
    }
    for (int i = 0; i < tableSize; ++i)
    {
        for (int j = 0; j < tableSize; ++j)
        {
            gameplay.table[i][j] = 0;
        }
    }
    // Tạo ngẫu nhiên 2 giá trị (2;2) hoặc (2;4) hoặc (4;4) khi bắt đầu chơi
    srand(time(NULL));
    int row1 = rand() % tableSize;
    int col1 = rand() % tableSize;
    int row2, col2;
    do
    {
        row2 = rand() % tableSize;
        col2 = rand() % tableSize;
    } while (row1 == row2 && col1 == col2);

    int val1 = (rand() % 2 + 1) * 2;
    gameplay.table[row1][col1] = val1;
    int val2 = (rand() % 2 + 1) * 2;
    gameplay.table[row2][col2] = val2;
    gameplay.score = 0;
}


void init_new_number(gamePlay2048 gameplay, int tableSize)
{
    if (!isZerotable(gameplay, tableSize))
        return;

    srand(time(NULL));
    int row, col;
    do
    {
        row = rand() % tableSize;
        col = rand() % tableSize;
    } while (gameplay.table[row][col] != 0);

    int quotient = rand() % 100;

    if (quotient >= 80)
        gameplay.table[row][col] = 4;
    else
        gameplay.table[row][col] = 2;
}