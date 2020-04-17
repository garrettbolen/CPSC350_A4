#include "DoublyLinkedList.h"
#pragma once

template <typename type> class GenQueue{
  public:
    GenQueue();
    ~GenQueue();

    void insert(type d);
    type remove();

    type peek();
    bool isEmpty();
    int getSize();

    int numElements;

    DoublyLinkedList<type>* myQueue;

};
