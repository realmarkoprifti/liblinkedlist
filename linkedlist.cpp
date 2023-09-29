#include <iostream>
#include "linkedlist.hpp"


ListNode *createLinkedList(int *numArr, int size)
{
    /*
        1. Gets a pointer to a number array
        2. Iterates through the arraw
        3. Creates a list's head
        4. For every element, creates a ListNode and appends it to the head
    */
    ListNode *head = NULL;

    for (int i = 0; i < size; i++)
    {
        ListNode *tmp = new ListNode;
        tmp->val = numArr[i];
        tmp->next = NULL;

        tmp->next = head;
        head = tmp; 
        delete tmp;
    }

    return head;
    
    delete head;
}


void insertElement(ListNode *head, int val)
{
    /*
        Creates a new ListNode and appends it to the end
        of the list.
    */
    ListNode *ptr = new ListNode;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->next == NULL)
        {
            ListNode *newVal = new ListNode;
            newVal->val = val;
            newVal->next = NULL;

            newVal->next = head;
            head = newVal;
        }
    }
}


void printLinkedList(ListNode *head)
{
    /*
        Iterates through the list and prints the ptr->val
    */
    ListNode *ptr = new ListNode;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->val << std::endl;
    }

    delete ptr;
}