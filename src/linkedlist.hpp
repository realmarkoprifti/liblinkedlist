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
};

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

        bool isSorted();
    
    public:

        LinkedList(int* numArr, int arrSize, int type);
        ~LinkedList();

        void insert(int val);
        void delNode(int val);
        int length();
        void sort();
        ListNode* search(int val);
        void print();
};


#endif