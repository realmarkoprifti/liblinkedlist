#include <iostream>
#include "linkedlist.hpp"


ListNode *createLinkedList(int *numArr, int size)
{
    ListNode *head = new ListNode;
    head = NULL;

    for (int i = 0; i < size; i++)
    {
        ListNode *newNode = new ListNode;
        newNode->val = numArr[i];
        newNode->prev = NULL;
        newNode->next = head;

        head = newNode;
    }

    return head;
}