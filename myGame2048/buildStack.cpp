#include"functions.h"

// Xây dựng stack bằng linked list

bool myStack::isEmptyStack()
{
    return head == NULL;
}

void myStack::push(gamePlay2048 value)
{
    Stack* newNode = new Stack(value);
    newNode->next = head;
    head = newNode;
    //size++;
}

gamePlay2048 myStack::pop1()
{
    if (isEmptyStack())
    {
        cout << "Can not pop1!\n";
    }
    gamePlay2048 data = head->value;
    Stack* temp = head;
    head = head->next;
    delete temp;
    return data;
}

gamePlay2048 myStack::pop2()
{
    if (isEmptyStack())
    {
        cout << "Can not pop2!\n";
    }
    return head->value;
}

gamePlay2048 myStack::top()
{
    if (isEmptyStack())
    {
        cout << "\033[19;1H" << RED << "Stack is empty! Can not undo!\n" << RESET;
    }
    return head->value;
}

void myStack::deleteMemoryStack()
{
    while (head != NULL)
    {
        Stack* temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}
