#include "DoublyLinkedList.h"
#include <cstddef>
#include <iostream>

using namespace std;

//Constructor
template <typename type> DoublyLinkedList<type>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template <typename type> unsigned int DoublyLinkedList<type>::getSize(){
  return size;
}

template <typename type> bool DoublyLinkedList<type>::isEmpty(){
  return (size == 0);
}

// template <typename type> void DoublyLinkedList<type>::printList(){
//   ListNode<type>* curr = front;
//   while(curr != NULL){
//     cout << curr->data << endl;
//     curr = curr->next;
//   }
// }

template <typename type> void DoublyLinkedList<type>::insertFront(type d){
  ListNode<type>* node = new ListNode<type>(d);
  if(isEmpty())
    back = node;
  else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

template <typename type> void DoublyLinkedList<type>::insertBack(type d){
  ListNode<type>* node = new ListNode<type>(d);
  if(isEmpty())
    front = node;
  else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <typename type> type DoublyLinkedList<type>::removeFront(){
  ListNode<type>* tempNode = front;
  //error check, make sure list is not empty
  if(front->next == NULL){
    //Only one node in list
    back == NULL;
  }
  else{
    //more than one node in list
    front->next->prev = NULL;
  }
  front = front->next;
  tempNode->next = NULL;
  type temp = tempNode->data;
  size--;
  delete tempNode;

  return temp;

}

// template <typename type> int DoublyLinkedList<type>::search(type val){
//   int pos = -1;
//   ListNode<type>* curr = front;
//   while(curr != NULL){
//     ++pos;
//     if(curr->data == val)
//       break;
//     else
//       curr == curr->next;
//     if(curr == NULL)
//       pos = -1;
//   }
//   return pos;
// }
//
// template <typename type> type DoublyLinkedList<type>::removeAtPos(int pos){
//   //error checking to make sure pos does not exceed size
//   int idx = 0;
//   ListNode<type>* curr = front;
//   ListNode<type>* prev = front;
//
//   while(idx != pos){
//     prev = curr;
//     curr = curr->next;
//     idx++;
//   }
//   prev->next = curr->next;
//   curr->next = NULL;
//   type temp = curr->data;
//   delete curr;
//   size--;
//
//   return temp;
// }
//
// template <typename type> type DoublyLinkedList<type>::remove(type value){
//   ListNode<type>* curr = front;
//
//   while(curr->data != value){
//     curr = curr->next;
//     if(curr == NULL)
//       return -1;
//   }
//   //if we make it here, then we found the value and must delete it
//   if(curr == front){
//     front = curr->next;
//   }
//
//   else if(curr == back){
//     back = curr->prev;
//   }
//   else{
//     curr->prev->next = curr->next;
//   }
//   curr->next = NULL;
//   curr->prev = NULL;
//   type temp = curr->data;
//   size--;
//   delete curr;
//   return temp;
// }
//
template <typename type> type DoublyLinkedList<type>::peek(){
  return front->data;
}

//This ensures a student and int DoublyLinkedList will be supported
template class DoublyLinkedList<Student>;
template class DoublyLinkedList<int>;
