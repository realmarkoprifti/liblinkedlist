#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define AUTHOR "Marko Prifti"

/*
    Linked list library written in C++ by Marko Prifti (me)
*/

class LinkedList
{
    private:
        struct ListNode
        {
            int val;
            ListNode* prev;
            ListNode* next;
        };

        ListNode* head;
        ListNode* tail;
        int length;

        void free();
        void createSinglyLinkedList(int* numArr, int size);
        void createDoublyLinkedList(int* numArr, int size);
    
    public:
        LinkedList(int* numArr, int arrSize, int type);
        ~LinkedList();

        void insert(int val);
        void delElem(int val);
        void length();
        void sort();
        ListNode* search(int val);
};


#endif