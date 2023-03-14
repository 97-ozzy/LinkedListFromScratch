#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;
    list.addFirst(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(0);
    auto array = list.toArray();
    cout << "Linked List: ";
    for(int i = 0; i < list.Size(); i++) {
        std::cout << array[i] << ", ";
    }
    cout << endl;
    cout << "Value of given index: "<< list.getKthFromTheEnd(1)<< endl;
    list.reverse();
    cout << "Reversed Linked List: ";
    auto reverseArray = list.toArray();
    for(int i = 0; i < list.Size(); i++) {
        std::cout << reverseArray[i] << ", ";
    }
    return 0;
}
