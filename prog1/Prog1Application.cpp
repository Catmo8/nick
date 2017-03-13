// Programming Project 1
// Frank Fontana, III <ffonta2@lsu.edu>

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "PriorityQueue.h"

using namespace std;

int main (int argc, char **argv) {
  
   if (argc != 2) {
     cout<<"Enter a valid file name."<<endl;
     exit(0);
   }

  //Accepts a file name as a command line argument and opens it
  fstream input;
  PriorityQueue *qP = new PriorityQueue;
  input.open(string(argv[1]).c_str(), ios::in);
  
  try {
     if (!input)
        throw "Enter a valid file name.";
  }
  catch (const char *e) {
     cout<<e<<endl;
     exit(0);
  }
   
  
  char c;
  while (input.get(c)) {  
     if (c != '!')
        qP->insert(c);      //Inserts a character if there is not an exclamation point.
     else
        cout<<qP->remove(); //Removes a character if there is an exclamation point.
  }
  
  input.close(); //Closes the file
  cout<<endl;
}
