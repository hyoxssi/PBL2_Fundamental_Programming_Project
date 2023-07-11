#include "Node.cpp"

#ifndef LinkedList_h
#define LinkedList_h

template <typename T>
class LinkedList {
    private:
        Node<T>* head;
    public:
        LinkedList();
        ~LinkedList();
        void insert_at_head(T value);
        void insert_at_tail(T value);
        void display();
        void deleteNodeAtGivenPos(int pos);
};

#endif