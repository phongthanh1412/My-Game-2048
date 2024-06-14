#pragma once

#include"functions.h"

// Hàm để đẩy trạng thái trò chơi hiện tại vào undoStack
void pushToUndoStack(gamePlay2048& gameplay, myStack& undoStack, int tableSize);

// Hàm để undo trạng thái trò chơi trước đó
void undoTable(gamePlay2048& gameplay, myStack& undoStack, myStack& redoStack, int tableSize);

// Hàm để redo trạng thái trò chơi vừa mới undo trước đó
void redoTable(gamePlay2048& gameplay, myStack& undoStack, myStack& redoStack, int tableSize);