/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "linkedStack.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a single line
// of code!

template <typename T> LinkedStack<T>::LinkedStack() {
    //memory leak in constructor
    this->StackList = new STLList<T>;
    this->size = 0; 
}


template <typename T> void LinkedStack<T>::push(T element) {
    //insertFirst
    this->StackList->insertFirst(element);
    this->size++; 
    //throw runtime_error("Not yet implemented: LinkedStack::push");
}

template <typename T> T LinkedStack<T>::pop() {
    //removeFirst
    //create sth that points to sth at the stack top
    //make a list, add that element and delete it
    //STLList<T>* removed = new STLList<T>;
    //removed->insertFirst(this->StackList->get(this->size - 1));
    this->size--;
    return this->StackList->removeFirst();
    //deallocate memory
    //delete removed;
    //throw runtime_error("Not yet implemented: LinkedStack::pop");
}

template <typename T> void LinkedStack<T>::insert(T element) {
    // To "insert" into a stack is to push onto it.  So when we are told to
    // insert, we will push.
    this->push(element);
}

template <typename T> T LinkedStack<T>::remove() {
    return this->pop();
    //throw runtime_error("Not yet implemented: LinkedStack::remove");
}

template <typename T> int LinkedStack<T>::getSize() {
    return this->size; 
    //throw runtime_error("Not yet implemented: LinkedStack::getSize");
}

template <typename T> bool LinkedStack<T>::isEmpty() {
    return this->StackList->isEmpty();
    
    //throw runtime_error("Not yet implemented: LinkedStack::isEmpty");
}

template <typename T> T LinkedStack<T>::peek() {
    return this->StackList->getFirst();
    //throw runtime_error("Not yet implemented: LinkedStack::peek");
}
