#include"functions.h"

void make_pseudo_table(gamePlay2048& gameplay, int**& pseudo_table, int tableSize)
{
    pseudo_table = new int* [tableSize];
    for (int i = 0; i < tableSize; i++)
        pseudo_table[i] = new int[tableSize];
    for (int i = 0; i < tableSize; i++)
        for (int j = 0; j < tableSize; j++)
            pseudo_table[i][j] = gameplay.table[i][j];
}

bool isChangetable(gamePlay2048 gameplay, int**& pseudo_table, int tableSize)
{
    for (int i = 0; i < tableSize; i++)
        for (int j = 0; j < tableSize; j++)
            if (pseudo_table[i][j] != gameplay.table[i][j])
                return 1;
    return 0;
}

void moveUp(gamePlay2048& gameplay, int tableSize)
{
    // Dồn các giá trị lên phía trên
    for (int j = 0; j < tableSize; j++)
    {
        int tmp = 0;
        for (int i = 0; i < tableSize; i++)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[tmp][j] = gameplay.table[i][j];
                if (i != tmp)
                    gameplay.table[i][j] = 0;
                tmp++;
            }
        }
        // Gộp các giá trị
        for (int i = 0; i < tableSize; i++)
        {
            if (i < tableSize - 1 && gameplay.table[i][j] == gameplay.table[i + 1][j])
            {
                gameplay.table[i][j] *= 2;
                gameplay.score += gameplay.table[i][j];
                gameplay.table[i + 1][j] = 0;
            }
        }
        // Dồn các giá trị lên phía trên một lần nữa tránh trường hợp sau khi gộp tồn tại giá trị 0,
        // và giúp đảm bảo các ô trống đều dồn lên cùng một phía
        tmp = 0;
        for (int i = 0; i < tableSize; i++)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[tmp][j] = gameplay.table[i][j];
                if (i != tmp)
                    gameplay.table[i][j] = 0;
                tmp++;
            }
        }
    }
}

void moveDown(gamePlay2048& gameplay, int tableSize)
{
    // Dồn các giá trị xuống phía dưới
    for (int j = 0; j < tableSize; j++)
    {
        int tmp = tableSize - 1;
        for (int i = tableSize - 1; i >= 0; i--)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[tmp][j] = gameplay.table[i][j];
                if (i != tmp)
                    gameplay.table[i][j] = 0;
                tmp--;
            }
        }
        // Gộp các giá trị
        for (int i = tableSize - 1; i >= 0; i--)
        {
            if (i >= 1 && gameplay.table[i][j] == gameplay.table[i - 1][j])
            {
                gameplay.table[i][j] *= 2;
                gameplay.score += gameplay.table[i][j];
                gameplay.table[i - 1][j] = 0;
            }
        }
        // Dồn các giá trị xuống phía dưới một lần nữa tránh trường hợp sau khi gộp tồn tại giá trị 0,
        // và giúp đảm bảo các ô trống đều dồn xuống cùng một phía
        tmp = tableSize - 1;
        for (int i = tableSize - 1; i >= 0; i--)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[tmp][j] = gameplay.table[i][j];
                if (i != tmp)
                    gameplay.table[i][j] = 0;
                tmp--;
            }
        }
    }
}

void moveLeft(gamePlay2048& gameplay, int tableSize)
{
    // Dồn các giá trị sang trái
    for (int i = 0; i < tableSize; i++)
    {
        int tmp = 0;
        for (int j = 0; j < tableSize; j++)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[i][tmp] = gameplay.table[i][j];
                if (j != tmp)
                    gameplay.table[i][j] = 0;
                tmp++;
            }
        }
        // Gộp các giá trị
        for (int j = 0; j < tableSize; j++)
        {
            if (j < tableSize - 1 && gameplay.table[i][j] == gameplay.table[i][j + 1])
            {
                gameplay.table[i][j] *= 2;
                gameplay.score += gameplay.table[i][j];
                gameplay.table[i][j + 1] = 0;
            }
        }
        // Dồn các giá trị trái một lần nữa tránh trường hợp sau khi gộp tồn tại giá trị 0,
        // và giúp đảm bảo các ô trống đều dồn sang cùng một phía
        tmp = 0;
        for (int j = 0; j < tableSize; j++)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[i][tmp] = gameplay.table[i][j];
                if (j != tmp)
                    gameplay.table[i][j] = 0;
                tmp++;
            }
        }
    }
}

void moveRight(gamePlay2048& gameplay, int tableSize)
{
    // Dồn các giá trị sang phải
    for (int i = 0; i < tableSize; i++)
    {
        int tmp = tableSize - 1;
        for (int j = tableSize - 1; j >= 0; j--)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[i][tmp] = gameplay.table[i][j];
                if (j != tmp)
                    gameplay.table[i][j] = 0;
                tmp--;
            }
        }
        // Gộp các giá trị
        for (int j = tableSize - 1; j > 0; j--)
        {
            if (j >= 1 && gameplay.table[i][j] == gameplay.table[i][j - 1])
            {
                gameplay.table[i][j] *= 2;
                gameplay.score += gameplay.table[i][j];
                gameplay.table[i][j - 1] = 0;
            }
        }
        // Dồn các giá trị phải một lần nữa tránh trường hợp sau khi gộp tồn tại giá trị 0,
        // và giúp đảm bảo các ô trống đều dồn sang cùng một phía
        tmp = tableSize - 1;
        for (int j = tableSize - 1; j >= 0; j--)
        {
            if (gameplay.table[i][j] != 0)
            {
                gameplay.table[i][tmp] = gameplay.table[i][j];
                if (j != tmp)
                    gameplay.table[i][j] = 0;
                tmp--;
            }
        }
    }
}

