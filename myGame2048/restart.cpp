#include"gameLogic.h"
#include"undo_redo.h"

void restartNewGame(gamePlay2048& gameplay, int& scores, myStack& undoStack, int**& pseudo_table, int tableSize)
{
    // Xoá toàn bộ dữ liệu trò chơi cũ 
    for (int i = 0; i < tableSize; i++)
    {
        delete[] gameplay.table[i];
        delete[] pseudo_table[i];
    }
    pseudo_table = NULL;
    // Tạo trạng thái trò chơi mới
    gameplay.table = new int* [tableSize];
    pseudo_table = new int* [tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        gameplay.table[i] = new int[tableSize];
        pseudo_table[i] = new int[tableSize];
    }
    init_table(gameplay, tableSize);
    scores = 0;
    pushToUndoStack(gameplay, undoStack, tableSize);
}