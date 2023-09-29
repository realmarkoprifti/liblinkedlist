#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
    Linked list library written in C++ by Marko Prifti (me)
    Will be extended to doubly-linked in the future
    Will add a deleteElement function
*/

struct ListNode
{
    int val;
    ListNode *prev;
    ListNode *next;
};


ListNode *createLinkedList(int *numArr, int size);
void insertElement(ListNode *head, int val);
void deleteElement(ListNode *head, int val);
int listLength(ListNode *head);
ListNode *sortList(ListNode *head);
void printLinkedList(ListNode *head);

#endif