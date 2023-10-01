#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define AUTHOR "Marko Prifti"

/*
    Linked list library written in C++ by Marko Prifti (me)
*/

struct ListNode
{
    int val;
    ListNode* prev;
    ListNode* next;
    bool isHead;
    bool isTail;
};


ListNode* createLinkedList(int *numArr, int size);
ListNode* createDoublyLinkedList(int *numArr, int size);
void insertElement(ListNode* head, int val);
ListNode* deleteElement(ListNode* head, int val);
int listLength(ListNode* head);
ListNode* sortList(ListNode* head);
void printLinkedList(ListNode* head);
void freeList(ListNode* head);
ListNode* searchElement(ListNode* head, int val);


#endif