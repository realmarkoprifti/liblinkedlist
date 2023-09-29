#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
    Singly-linked list library written in C++ by Marko Prifti (me)
    Will be extended to doubly-linked in the future
    Will add a deleteElement function
*/

struct ListNode
{
    int val;
    ListNode *next;
};

struct DoubleListNode
{
    int val;
    ListNode *prev;
    ListNode *next;
};


ListNode *createLinkedList(int *numArr, int size);
void insertElement(ListNode *head, int val);
void printLinkedList(ListNode *head);

#endif