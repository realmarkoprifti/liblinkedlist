#include <iostream>
#include "linkedlist.hpp"


ListNode *createLinkedList(int *numArr, int size)
{
    if (size <= 1)
    {
        return NULL;
    }

    ListNode *head = new ListNode;
    head = NULL;

    for (int i = 0; i < size; i++)
    {
        ListNode *newNode = new ListNode;
        newNode->val = numArr[i];
        newNode->prev = NULL;
        newNode->next = head;
        newNode->isHead = false;
        newNode->isTail = false;

        if (i == 0)
        {
            newNode->isTail = true;
        }

        else if (i == size - 1)
        {
            newNode->isHead = true;
        }

        head = newNode;
    }

    return head;
}


ListNode *createDoublyLinkedList(int *numArr, int size)
{
    if (size <= 1)
    {
        return NULL;
    }

    ListNode *head = new ListNode;
    head = NULL;

    for (int i = 0; i < size; i++)
    {
        ListNode *newNode = new ListNode;
        newNode->val = numArr[i];
        newNode->next = head;
        newNode->isHead = false;
        newNode->isTail = false;

        if (i == 0)
        {
            newNode->isTail = true;
        }

        else if (i == size - 1)
        {
            newNode->isHead = true;
        }

        head = newNode;
    }

    ListNode *ptr = new ListNode;
    ListNode *prev = new ListNode;
    prev = NULL;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        ptr->prev = prev;

        if (ptr->isHead)
        {
            ptr->prev = NULL;
        }

        prev = ptr;
    }

    delete ptr;
    delete prev;

    return head;
}


int listLength(ListNode *head)
{
    int length = 0;

    ListNode *ptr = new ListNode;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        length++;
    }

    delete ptr;

    return length;
}


void printLinkedList(ListNode *head)
{
    ListNode *ptr = new ListNode;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->val << std::endl;
    }

    delete ptr;
}