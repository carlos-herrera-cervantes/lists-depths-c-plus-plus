#include <iostream>

class LinkedListNode 
{
    public:
        int value;
        LinkedListNode *next;

        LinkedListNode(int value)
        {
            this->value = value;
            this->next = NULL;
        }
};