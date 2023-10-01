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
    ListNode *prev = head;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->isHead && ptr->val == val)
        {
            ListNode *tmp = ptr->next;
            delete ptr;
            head = tmp;

            if (head != NULL)
            {
                head->isHead = true;
                head->prev = NULL;
            }
        }

        else if (ptr->isTail && ptr->val == val)
        {
            delete ptr;
            prev->isTail = true;
            prev->next = NULL;
            ptr = prev;

        }

        else if (ptr->val == val)
        {

            // Check if the list is doubly linked
            if (ptr->prev != NULL)
            {
                prev->next = ptr->next;
                ptr->next->prev = prev;
                delete ptr;
            }   
            
            // Else it's singly linked
            else 
            {
                prev->next = ptr->next;
                delete ptr;
            } 
        }

        prev = ptr;
    }

    return head;
}