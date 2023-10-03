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
}


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


int LinkedList::length()
{
    int length = 0;

    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        length++;
    }

    return length;
}


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


void LinkedList::delNode(int val)
{

    ListNode* ptr = NULL;
    ListNode* prev = head;

    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (head == ptr && ptr->val == val)
        {
            std::cout << "Deleting head node..." << std::endl;
            ListNode* tmp = ptr->next;
            delete ptr;
            head = tmp;

            if (head != NULL)
            {
                head->prev = NULL;
            }
        }

        else if (tail == ptr && ptr->val == val)
        {
            delete ptr;
            tail = prev;
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

        // Just for the aesthetics
        else
        {
            continue;
        }

        prev = ptr;
    }
}


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


void LinkedList::print()
{
    for (ListNode* ptr = head; ptr != NULL; ptr = ptr->next)
    {
        std::cout << ptr->val << std::endl;
    }
}