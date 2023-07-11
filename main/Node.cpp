#include "Node.h"

template <typename T>
Node<T>::Node(T n) {
    prev = NULL;
    data = n;
    next = NULL;
}