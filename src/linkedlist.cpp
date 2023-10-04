#include <iostream>
#include "linkedlist.hpp"


/*
 Linked List constructor to initialize singly and doubly linked lists.
 Type should be 1 for singly linked list and 2 for doubly linked list.
*/
LinkedList::LinkedList(int* numArr, int arrSize, int type)
{
    if (type == 1)
    {
        for (int i = 0; i < arrSize; i++)
        {
            ListNode* newNode = new ListNode;
            newNode->val = numArr[i];
            newNode->next = head;
            newNode->prev = NULL;

            if (i == 0)
            {
                tail = newNode;
            }

            head = newNode;
        }
    }

    else if (type == 2)
    {
        for (int i = 0; i < arrSize; i++)
        {
            ListNode* newNode = new ListNode;
            newNode->val = numArr[i];
            newNode->prev = NULL;
            newNode->next = head;

            if (i == 0)
            {
                tail = newNode;
            }

            head = newNode;
        }

        ListNode* prev = NULL;

        for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
        {
            ptr->prev = prev;
            prev = ptr;
        }
    }

    else
    {
        throw std::invalid_argument(
            "Invalid type of linked list. 1 -> Singly linked list, 2 -> Doubly linked list"
            );
    }

    listType = type;
}

// Automatically frees the list when the object is deconstructured
LinkedList::~LinkedList()
{
    ListNode* ptr = head;

    while (ptr != NULL)
    {
        ListNode* tmp = ptr->next;
        delete ptr;
        ptr = tmp;

    }
}


// Returns an int containing the lists' length
int LinkedList::length()
{
    int length = 0;

    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        length++;
    }

    return length;
}


// Inserts a node at the end of the list
void LinkedList::insert(int val)
{
    ListNode* newNode = new ListNode;

    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (tail == ptr)
        {
            newNode->val = val;
            ptr->next = newNode;
            tail = newNode;

            if (ptr->prev != NULL)
            {
                newNode->prev = ptr;
                tail = newNode;
                newNode->next = NULL;

                return;
            }

            else
            {
                newNode->next = NULL;
                newNode->prev = NULL; 
            }
        }
    }
}


// Deletes the first occurrence of a node with the given value
void LinkedList::delNode(int val)
{
    ListNode* prev = head;

    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->val == val)
        {
            if (ptr == head)
            {
                if (listType == 1)
                {
                    ListNode* tmp = ptr->next;
                    delete ptr;
                    head = tmp;
                }

                else
                {
                    ListNode* tmp = ptr->next;
                    tmp->prev = NULL;
                    delete ptr;
                    head = tmp;
                }
            }

            else if (ptr == tail)
            {
                prev->next = NULL;
                delete ptr;
                tail = prev;
            }

            else
            {
                if (listType == 1)
                {
                    ListNode* tmp = ptr->next;
                    prev->next = tmp;
                    delete ptr;

                    return;
                }

                else
                {
                    ListNode* tmp = ptr->next;
                    prev->next = tmp;
                    tmp->prev = prev;

                    delete ptr;
                    return;
                }
            }
        }

        prev = ptr;
    }
}


// Returns true if the list is sorted
bool LinkedList::isSorted()
{
    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr != tail)
        {
            if (ptr->val > ptr->next->val)
            {
                return false;
            }
        }
    }

    return true;
}


// Sorts the list using the bubble sort algorithm
void LinkedList::sort()
{
    /*
        This function uses the Bubble Sort
        algorithm to sort the list
    */
    bool sorted = isSorted();

    while (!sorted)
    {
        for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr != tail)
            {
                if (ptr->val > ptr->next->val)
                {
                    int tmp = ptr->val;
                    ptr->val = ptr->next->val;
                    ptr->next->val = tmp;
                }
            }
        }

        sorted = isSorted();
    }
}


// Prints the list's node values
void LinkedList::print()
{
    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->val << std::endl;
    }
}


// Uses Linear Seach to search for a node with the given value. Returns the node if found, else NULL.
ListNode* LinkedList::lsearch(int val)
{
    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->val == val)
        {
            return ptr;
        }
    }

    return NULL;
}