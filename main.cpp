#include <iostream>
#include "LinkedList.h"


int main() {
    LinkedList list;
    list.addFirst(1);
    list.addLast(2);
    list.addLast(3);
    auto array = list.toArray();
    for(int i = 0; i < list.Size(); i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}
