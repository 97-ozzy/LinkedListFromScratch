#ifndef LINKEDLISTFROMSCRATCH_LINKEDLIST_H
#define LINKEDLISTFROMSCRATCH_LINKEDLIST_H


#include <iostream>
#include <exception>

class LinkedList {
    class Node {
    private:
        int value;
        Node *next=NULL;

    public:
        void setNext(Node *next) {
            Node::next = next;
        }

        int getValue() const {
            return value;
        }

        Node *getNext() const {
            return next;
        }

        Node(int value) {
            this->value = value;
        }
    };
private:
    Node* first;
    Node* last;

    bool isEmpty(){
        return first==NULL;
    }
    Node getPrevious(Node *node) {
        auto current = first;
        while (current->getNext()!= NULL) {
            if(current->getNext() == node) return *current;
            current = current->getNext();
        }
        return NULL;
    }
public:
    int size=0;
    explicit LinkedList();

    void addFirst(int value);
    void addLast(int value);

    int indexOf(int value);
    bool contains(int value);

    void removeFirst();
    void removeLast();

    int Size();

    int* toArray();

    void reverse();

    int getKthFromTheEnd(int k);

};



#endif
