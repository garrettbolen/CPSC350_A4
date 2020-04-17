#include "GenQueue.h"

template <typename type> GenQueue<type>::GenQueue(){
  myQueue = new DoublyLinkedList<type>();
  numElements = 0;
}

template <typename type> GenQueue<type>::~GenQueue(){
  delete myQueue;
}

template <typename type> void GenQueue<type>::insert(type d){
  //add error checking
  myQueue->insertBack(d);
  ++numElements;
}

template <typename type> type GenQueue<type>::remove(){
  type data = myQueue->removeFront();
  numElements--;
  return data;
}

template <typename type> type GenQueue<type>::peek(){
  return myQueue->peek();
}

template <typename type> bool GenQueue<type>::isEmpty(){
  return (numElements == 0);
}

template <typename type> int GenQueue<type>::getSize(){
  return numElements;
}

//This ensures an int queue will be supported
template class GenQueue<int>;
