#include"prepareForGame.h"
#include"gameLogic.h"
#include"undo_redo.h"

void pushToUndoStack(gamePlay2048& gameplay, myStack& undoStack, int tableSize)
{
    gamePlay2048 newgameplay;
    newgameplay.table = new int* [tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        newgameplay.table[i] = new int[tableSize];
        for (int j = 0; j < tableSize; j++)
        {
            newgameplay.table[i][j] = gameplay.table[i][j];
        }
    }
    newgameplay.score = gameplay.score;
    undoStack.push(newgameplay);
}

void undoTable(gamePlay2048& gameplay, myStack& undoStack, myStack& redoStack, int tableSize)
{
    if (!undoStack.isEmptyStack() && (undoStack.head)->next != NULL)
    {
        gamePlay2048 nextgameplay = undoStack.top();
        undoStack.pop1();
        redoStack.push(nextgameplay);
        gamePlay2048 prevgameplay = undoStack.top();
        for (int i = 0; i < tableSize; i++)
            for (int j = 0; j < tableSize; j++)
                gameplay.table[i][j] = prevgameplay.table[i][j];
        gameplay.score = prevgameplay.score;
    }
    else
    {
        gotoxy(60, 14);
        cout << COLOR_BACKGROUND_g << WHITE << "                                        " << RESET << endl;
        gotoxy(60, 15);
        cout << COLOR_BACKGROUND_g << WHITE << " Stack is empty! Can not undo!          " << RESET << endl;
        gotoxy(60, 16);
        cout << COLOR_BACKGROUND_g << WHITE << " Press any 'control' key to continue... " << RESET << endl;
        gotoxy(60, 17);
        cout << COLOR_BACKGROUND_g << WHITE << "                                        " << RESET << endl;

        bool cannotUndo = 1;
        // Tiếp tục chơi khi người chơi nhấn phím "di chuyển" khác
        while (cannotUndo)
        {
            char noti = _getch();
            if (noti != 'u')
            {
                cannotUndo = 0;
            }
        }
        gotoxy(60, 14);
        cout << ERASE;
        gotoxy(60, 15);
        cout << ERASE;
        gotoxy(60, 16);
        cout << ERASE;
        gotoxy(60, 17);
        cout << ERASE;

    }
}

void redoTable(gamePlay2048& gameplay, myStack& undoStack, myStack& redoStack, int tableSize)
{
    if (!redoStack.isEmptyStack())
    {
        gamePlay2048 prevgameplay = redoStack.top();
        redoStack.pop1();
        undoStack.push(prevgameplay);
        gamePlay2048 nextgameplay = undoStack.top();
        for (int i = 0; i < tableSize; i++)
            for (int j = 0; j < tableSize; j++)
                gameplay.table[i][j] = nextgameplay.table[i][j];
        gameplay.score = nextgameplay.score;
    }
    else
    {
        gotoxy(60, 14);
        cout << COLOR_BACKGROUND_g << WHITE << "                                                        " << RESET << endl;
        gotoxy(60, 15);
        cout << COLOR_BACKGROUND_g << WHITE << " Stack is empty or one operation was implemented after  " << RESET << endl;
        gotoxy(60, 16);
        cout << COLOR_BACKGROUND_g << WHITE << " the undo one!                                          " << RESET << endl;
        gotoxy(60, 17);
        cout << COLOR_BACKGROUND_g << WHITE << " Can not redo!                                          " << RESET << endl;
        gotoxy(60, 18);
        cout << COLOR_BACKGROUND_g << WHITE << " Press any 'control' key to continue...                 " << RESET << endl;
        gotoxy(60, 19);
        cout << COLOR_BACKGROUND_g << WHITE << "                                                        " << RESET << endl;

        bool cannotRedo = 1;
        // Tiếp tục chơi khi người chơi nhấn phím "di chuyển" khác
        while (cannotRedo)
        {
            char noti = _getch();
            if (noti != 'r')
            {
                cannotRedo = 0;
            }
        }
        gotoxy(60, 14);
        cout << ERASE;
        gotoxy(60, 15);
        cout << ERASE;
        gotoxy(60, 16);
        cout << ERASE;
        gotoxy(60, 17);
        cout << ERASE;
        gotoxy(60, 18);
        cout << ERASE;
        gotoxy(60, 19);
        cout << ERASE;
    }
}
