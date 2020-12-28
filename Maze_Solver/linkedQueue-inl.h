/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "linkedQueue.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a single line
// of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
    //memory leak in constructor
    this->QueueList = new STLList<T>;
    this->size = 0; 
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
    this->QueueList->insertLast(element);
    this->size++; 
    //throw runtime_error("Not yet implemented: LinkedQueue::enqueue");
}

template <typename T> T LinkedQueue<T>::dequeue() {
    this->size--;
    return this->QueueList->removeFirst();  
    
    //throw runtime_error("Not yet implemented: LinkedQueue::dequeue");
}

template <typename T> void LinkedQueue<T>::insert(T element) {
    // NOTE: for a hint on how to implement this, see LinkedStack<T>::insert
    return this->enqueue(element);
    //throw runtime_error("Not yet implemented: LinkedQueue::insert");
}

template <typename T> T LinkedQueue<T>::remove() {
    return this->dequeue(); 
    //throw runtime_error("Not yet implemented: LinkedQueue::remove");
}

template <typename T> int LinkedQueue<T>::getSize() {
    return this->size; 
    //throw runtime_error("Not yet implemented: LinkedQueue::getSize");
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
    return this->QueueList->isEmpty();
    //throw runtime_error("Not yet implemented: LinkedQueue::isEmpty");
}

template <typename T> T LinkedQueue<T>::peek() {
    return this->QueueList->getFirst();
    //throw runtime_error("Not yet implemented: LinkedQueue::peek");
}
