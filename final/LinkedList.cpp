#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList() {}

template <typename T>
void LinkedList<T>::insert_at_head(T value) {
    Node<T>* n = new Node<T>(value);
	n->next = this->head;
	if (this->head != NULL) {
		this->head->prev = n;
	}
	this->head = n;
}

template <typename T>
void LinkedList<T>::insert_at_tail(T value) {
    if (this->head == NULL) {
		insert_at_head(value);
		return;
	}
	Node<T>* n = new Node<T>(value);
	Node<T>* temp = this->head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

template <typename T>
void LinkedList<T>::display() {
	int i = 1;
	Node<T>* temp = this->head;
	while (temp != NULL) {
		if (i < 10) cout << i << ".  " << temp->data << endl;
		else cout << i << ". " << temp->data << endl;
		++i;
		temp = temp->next;
	}
	// cout << "NULL" << endl;
}

template <typename T>
void LinkedList<T>::deleteNodeAtGivenPos(int pos) {
    if (this->head == NULL || pos <= 0)
        return;
    struct Node<T>* current = this->head;
    for (int i = 1; current != NULL && i < pos; i++)
        current = current->next;
    if (current == NULL)
        return;
    if (this->head == NULL || current == NULL)
        return;
    if (this->head == current)
        this->head = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = current->next;
    free(current);
}