/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <iostream>
#include <string>
#include <utility>
#include "linkedStack.h"
#include "linkedQueue.h"

#include "adts/list.h"
// TODO: put #includes here

using namespace std;

int main() {
    // TODO: write any tests you want here; this is your sandbox
    //creating a linkedstack
    LinkedStack<int>* Stack = new LinkedStack<int>(); 
    for(int i=1; i<6; i++){
      Stack->push(i);
      cout<<Stack->peek() <<endl;
    }
    //delete Stack;
    //tried to pop everything out of the stack
    int Popped;
    while(!(Stack->isEmpty())){
      Popped = Stack->pop();
      cout<<Popped <<endl;
    }
    //didnt help with memory leaks
    //delete Stack;
    
    LinkedQueue<int>* Queue = new LinkedQueue<int>(); 
    //
    for(int i=1; i<6; i++){
      Queue->enqueue(i);
      cout<<Queue->peek() <<endl;
    }
    //delete Stack;
    //tried to pop everything out of the stack
    int removed;
    while(!(Queue->isEmpty())){
      removed = Queue->dequeue();
      cout<< removed <<endl;
    }

    //delete Queue;
      

    return 0;
}
