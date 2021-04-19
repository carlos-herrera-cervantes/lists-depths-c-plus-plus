#include <iostream>
#include "linkedListNode.cpp"

using namespace std;

class LinkedList
{
    LinkedListNode *head;
    LinkedListNode *tail;
    int length;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    /**
    * Prints all nodes in the linked list
    */
    void print_all()
    {
        LinkedListNode *temp;
        temp = head;

        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
    }

    /**
    * Insert new node
    * @param value Value to insert
    */
    void insert(int value)
    {
        LinkedListNode *temp = new LinkedListNode(value);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }

        length++;
    }
};