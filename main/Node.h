#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

#ifndef Node_h
#define Node_h

template <typename T>
class Node {
    public:
        Node<T>* prev;
        T data;
        Node<T>* next;
        Node(T n);
};

#endif