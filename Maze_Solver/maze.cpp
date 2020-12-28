/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <stdexcept>
#include <iostream>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {
    //step needed: first array: each element is pointer to array of position pointers
    this->positions = new Position**[width];
    for(int i=0; i < width; i++){ //width is x
        //step needed: second array
        this->positions[i] = new Position*[height];
        for(int k=0; k<height; k++){  //height is y
            this->positions[i][k] = new Position (i, k);
            //For example, positions[0][0] will obtain the 
            //pointer (Position*) to the Position object in the upper-left corner.
        }
    }
    this->width = width;
    this->height = height;

}

Maze::~Maze() {
    
    //delete all position objects
    
    for(int i = 0; i < width; i++){
        for(int k = 0; k < height; k++) {
            delete this->positions[i][k];
        } 
    }
    //delete height arrays
    for(int i = 0; i < width; i++) {
        delete[] this->positions[i];
    }
    
    delete[] this->positions;
    
}

int Maze::getWidth() {
    return this->width; 
    
}

int Maze::getHeight() {
    return this->height;
}

bool Maze::isWall(int x, int y) {
    //check if the position's' this->wall is true
    return this->positions[x][y]->isWall(); //returns either true or false
}

void Maze::setWall(int x, int y) {
    //sets the position's this-> wall to true
    this->positions[x][y]->setWall();
}

List<Position*>* Maze::solveBreadthFirst() {
    //create queue to store position pointers: and call solve
    LinkedQueue<Position*>* MazeQueue = new LinkedQueue<Position*>();
    List<Position*>* solution = this->solve(MazeQueue);
    return solution;
}  

List<Position*>* Maze::solveDepthFirst() {
    //create stack to store position pointers: and call solve

    LinkedStack<Position*>* MazeStack = new LinkedStack<Position*>();
    List<Position*>* solution = this->solve(MazeStack);
    return solution;
}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
    //write solving code here for arbitrary list(queue or stack)
    //empty queue/stack taken in

    Position* currPos = this->positions[0][0];
    exploration->insert(currPos);
    currPos->setVisited();
    //to be used in while loop
    List<Position*>* Neighbors;
    Position* neighbor;
    List<Position*>* solution = new STLList<Position*>;
    int last_w = this->width -1;
    int last_h = this->height -1;
   
    bool condition = true;
    while(!exploration->isEmpty()){ 
        currPos = exploration->remove();  //remove from stack/queue
        if(currPos == this->positions[last_w][last_h]){ //exit loop
            break;
        }
        else{
            //mark as visited, remove point from exploration and put its neighbors in-exploration-> 
            //each time you explore, set neighbors previous to current.
             //exploration keeps track of places that we shud explore
            //check neighbors
            Neighbors = getNeighbors(currPos); //doesn't return walls
            for(int i=0; i<(Neighbors->getSize()); i++){
                neighbor = Neighbors->get(i);
                if(!(neighbor->isVisited())){ //if not yet visited, set visited to true
                    neighbor->setVisited();
                    //set Neighbor's prev to point to currPos
                    neighbor->setPrevious(currPos);
                    //add neighbor to queue/stack if not visited
                    exploration->insert(neighbor);
                }
                //if neighbor is visited, move to the next neighbor
            }
        }           
    }
    //read from currPos and keep on inserting first into a solution list, 
    //using the previous pointer: point->getPrevious()
    if(currPos == this->positions[last_w][last_h]){
        solution->insertFirst(currPos);     
        while(currPos->getPrevious() != nullptr){
            currPos = currPos->getPrevious();
            solution->insertFirst(currPos);
        }
    }
    else{
        solution = nullptr;
    }
    return solution;
}

List<Position*>* Maze::getNeighbors(Position* position) {
    //x < width  y < height
    //array of position pointers: could make this an STL list 
    //since size ranges from 2 to 4, and you can get size
    int x = position->getX();
    int y = position->getY();
    int w = this->width;
    int h = this->height;
    List<Position*>* neighbors = new STLList<Position*>;
    if(position->getY() < (h - 1)){ //read down: x, y+1
        Position* neighbor1 = this->positions[x][y+1];
        //insert only if this is not a wall
        if(!(this->isWall(neighbor1->getX(), neighbor1->getY()))){
            neighbors->insertLast(neighbor1);
        }
        //maybe delete neighbor after?
    }

    if(position->getX() < (w - 1)){ //read right: x+1, y
        Position* neighbor2 = this->positions[x+1][y];
        if(!(this->isWall(neighbor2->getX(), neighbor2->getY()))){
            neighbors->insertLast(neighbor2);
        }   
    }

    if(position->getX() > 0){ //read left: x-1, y
        Position* neighbor3 = this->positions[x-1][y];
        if(!(this->isWall(neighbor3->getX(), neighbor3->getY()))){
            neighbors->insertLast(neighbor3);
        }          
    }

    if(position->getY() > 0){ //read up: x, y-1
        Position* neighbor4 = this->positions[x][y-1];
        if(!(this->isWall(neighbor4->getX(), neighbor4->getY()))){
            neighbors->insertLast(neighbor4);
        } 
    }
    
    return neighbors;
    //for(int x = position->getX; x < width; x++)
    //check right, down, left and up(in this order)
    //(x-1,y) and(x+1,y) -left and right 
    //(x, y-1) and (x, y+1): up and down
    //add them to a list and return the list
    //throw runtime_error("Not yet implemented: Maze::getNeighbors");
}
