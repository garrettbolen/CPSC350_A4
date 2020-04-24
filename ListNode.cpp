#include "ListNode.h"
#include <cstddef>

template <typename type> ListNode<type>::ListNode(){
  // data = NULL;
  next = NULL;
  prev = NULL;
}

template <typename type> ListNode<type>::ListNode(type d){
  data = d;
  next = NULL;
  prev = NULL;
}

template <typename type> ListNode<type>::~ListNode(){

}

//This ensures Student and int list nodes will be supported
template class ListNode<Student>;
template class ListNode<int>;
