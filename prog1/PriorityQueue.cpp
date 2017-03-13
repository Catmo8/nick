// Programming Project 1
// Frank Fontana, III <ffonta2@lsu.edu>

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include "PriorityQueue.h"

using namespace std;

//This function returns the size of the array.
int PriorityQueue::size() {
  return array_size;
}

//This function inserts a character into the array and then heapifies it.
void PriorityQueue::insert(char a) {
  if (array_size >= 255)
     cout<<"The data in the array has exceeded the parameters."<<endl;
  else {
     priorityQueue[array_size] = a;
     array_size++;
     if (array_size > 1) {
        int i = array_size - 1;
        int parent;
     
        while (i > 0) {
           parent = (i - 1) / 2;
           if ( priorityQueue[parent] > priorityQueue[i]) {
              swap(priorityQueue[parent], priorityQueue[i]);  //Swaps the parent element with the child element.
              i = parent;                                     //The variable "i" is updated to the parent of the child, so 
                                                              //that the next parent may be calculated if needed.
           }
           else 
              break;
        }
     }
  } 
}

//Removes a character from the array and then returns it.
char PriorityQueue::remove() {
  if (array_size == 0) {
     return 0; //Returns NULL character.
  }
  else {
     char temp = priorityQueue[0];
     swap(priorityQueue[0],priorityQueue[array_size - 1]);
     priorityQueue[array_size - 1] = 0;
     array_size--;
     if(array_size > 1) {
        int i = 0;
        int parent = 0;
        int left;
        int right;
        
        while (i < array_size) {
           parent = i;
           left   = (i * 2) + 1;
           right  = (i * 2) + 2;
           
           //Checks to see if both the left and the right child exist.
           if (priorityQueue[left] != 0 && priorityQueue[right] != 0) 
              if (priorityQueue[parent] > priorityQueue[left] || priorityQueue[parent] > priorityQueue[right]) {
                 if (priorityQueue[left] > priorityQueue[right]) {
                    swap(priorityQueue[right], priorityQueue[parent]);  //Swaps either left or right child if parent is greater than
                    i = right;                                          //both children.
                 }
                 else {
                    swap(priorityQueue[left], priorityQueue[parent]);
                    i = left;
                 }
              }
              else
                 return temp;                   
           else if (priorityQueue[left] != 0)   //Checks to see if only the left child exists.
              if (priorityQueue[parent] > priorityQueue[left]) {
                 swap(priorityQueue[left], priorityQueue[parent]);
                 i = left;
              }
              else
                 return temp;
           else
              i++; //Increments i. 
        }
     }
     return temp; //Returns character that was removed.
  } 
}

//This function will clear the entire array and 
//set the size of the array equal to 0.
void PriorityQueue::clear() {
   int i = 0;
   while (i < 255) {
     priorityQueue[i] = 0;
     i++;
   }
   array_size = 0;
}

//This funcion will add a character to the end of the array
//regardless of heap order. 
void PriorityQueue::append(char a) {
  if (array_size < 255) {
     priorityQueue[array_size] = a;
     array_size++;
  }
  else
     cout<<"The size of the array was exceeded."<<endl; //Error message.
}

//This function will check to see if the array is in heap-order.
//It will return a truth value whether or not it is in heap-order.
bool PriorityQueue::check() {
  int pos = 0;
  int left;
  int right;
  while (pos < array_size) {
     left  = (2 * pos) + 1;
     right = (2 * pos) + 2;
     if (left >= array_size)
        return true;
     if(priorityQueue[left] != 0)
        if (priorityQueue[pos] > priorityQueue[left])
           return false;
     if(right >= array_size)
        return true;
     if(priorityQueue[right] != 0)
        if (priorityQueue[pos] > priorityQueue[right])
           return false;
     pos++;
  }
  return true;
}
