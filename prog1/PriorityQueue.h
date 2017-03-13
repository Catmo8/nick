// Programming Project 1
// Frank Fontana, III <ffonta2@lsu.edu>

#include <iostream>

class PriorityQueue {
  private:
     char priorityQueue[255];  //There are 255 characters in this declared array.
     int  array_size;          //Size of array

  public:
     int size();
     void insert(char a);
     char remove();

     void clear();
     void append(char a);
     bool check();
};
