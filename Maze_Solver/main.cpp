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

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {
      
    List<Position*>* Solution;
    if(argc == 3){
      try{
          Maze* Unsolved = loadMap(argv[1]);
          string str1 = argv[2];
          if(str1 == "breadth"){ 
            Solution = Unsolved->solveBreadthFirst();  
          }
              
          else if(str1 == "depth"){ 
             Solution = Unsolved->solveDepthFirst();  
          }
          else{
            throw runtime_error("Invalid arguments!");
          }
          if(Solution == nullptr){  //no solution
            cout<<"The maze has no solution."<<endl;
          }
          else{
            string Answer = renderAnswer(Unsolved, Solution);
            cout<<Answer<<endl;
          }
          delete Unsolved; //memory deallocation
   
      }
      catch(runtime_error e){ 
        //dealing with errors in loadMap() or invalid search type
        cout<<"Invalid file or search type entries!"<<endl;
      }
      
    }
    else {
      cout << "Incorrect number of arguments!" << endl; 
    }
    return 0;
}
