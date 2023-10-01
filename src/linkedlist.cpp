#include <iostream>
#include "linkedlist.hpp"


ListNode *createLinkedList(int *numArr, int size)
{
    if (size <= 1)
    {
        return NULL;
    }

    ListNode *head = NULL;

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

    ListNode *head = NULL;

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

    ListNode *ptr = NULL;
    ListNode *prev = NULL;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        ptr->prev = prev;
        prev = ptr;
    }

    delete ptr;

    return head;
}


int listLength(ListNode *head)
{
    int length = 0;

    ListNode *ptr = NULL;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        length++;
    }

    return length;
}


void printLinkedList(ListNode *head)
{
    ListNode *ptr = NULL;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->val << std::endl;
    }

}


void freeList(ListNode *head)
{
    ListNode *ptr = head;

    while (ptr != NULL)
    {
        ListNode *tmp = ptr->next;
        delete ptr;
        ptr = tmp;

    }
}


ListNode *deleteElement(ListNode *head, int val)
{
    ListNode *ptr = NULL;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->isHead && ptr->val == val)
        {
            ptr->isHead = false;
            ListNode *tmp = ptr->next;
            tmp->isHead = true;
            tmp->prev = NULL;
            delete ptr;
            head = tmp;
        }

        else if (ptr->next->isTail && ptr->next->val == val)
        {
            ptr->next->isTail = false;
            delete ptr->next;
            ptr->next = NULL;
            ptr->isTail = true;
        }

        else 
        {
              
        }

    }

    return head;
}