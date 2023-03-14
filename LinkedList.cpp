//
// Created by 97ozzy on 3/14/2023.
//

#include "LinkedList.h"
#include <iostream>
#include <exception>

using namespace std;

LinkedList::LinkedList()
{
    first = NULL;
    last = NULL;
}

void LinkedList:: addFirst(int value){
    Node *node = new Node(value);
    if (isEmpty())
        first = last = node;
    else{
        node->setNext(first);
        first = node;
    }
    size++;
}
void LinkedList:: addLast(int value){
    Node *node = new Node(value);
    if (isEmpty())
        first = last = node;
    else {
        last->setNext(node);
        last = node;
    }
    size++;
}

int LinkedList:: indexOf(int value) {
    int index = 0;
    Node *temp = first;
    while (temp!= NULL) {
        if(temp->getValue()==value) return index;
        temp = temp->getNext();
        index++;

    }
    return -1;
}
bool LinkedList:: contains(int value) {
    Node *temp = first;
    while (temp!= NULL) {
        if(temp->getValue()==value) return true;
        temp = temp->getNext();
    }
    return false;
}

void LinkedList:: removeFirst() {
    if(isEmpty()) throw std::out_of_range("List is empty");
    if(first == last) first = last = NULL;
    else {
        auto second = first->getNext();
        first->setNext(NULL);
        first = second;
    }
    size--;
}
void LinkedList:: removeLast() {
    if(isEmpty()) throw std::out_of_range("List is empty");
    if(first == last)
        first = last = NULL;
    else {
        auto previous = getPrevious(last);
        *last = previous;
        last->setNext(NULL);
    }

    size--;
}

int LinkedList:: Size() {
    return size;
}

int* LinkedList:: toArray() {
    int* array;
    array = new int[size];
    auto current = first;
    int index = 0;
    while (current!= NULL) {
        array[index++] = current->getValue();
        current = current->getNext();
    }
    return array;
}

void LinkedList:: reverse() {
    auto previous = first;
    auto current = first->getNext();
    while (current!=NULL) {
        auto next = current->getNext();
        current->setNext(previous);
        previous = current;
        current = next;
    }

    last = first;
    last->setNext(NULL);
    first = previous;
}

int LinkedList:: getKthFromTheEnd(int k) {
    if (isEmpty()) throw std::out_of_range("List is empty");
    if (k <= 0) throw std::out_of_range("Index out of range");
    if (k > size) throw std::out_of_range("Index out of range");
    if (k == 1) return last->getValue();
    if (k == size) return first->getValue();

    auto index = first;
    auto edge=first;
    for (int i = 0; i < k; i++) {
        edge = edge->getNext();
    }
    while (edge!=NULL) {
        edge = edge->getNext();
        index = index->getNext();
    }
    return index->getValue();
}