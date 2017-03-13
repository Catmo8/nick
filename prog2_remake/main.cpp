//Programming Project 2
//Frank Fontana, III <ffonta2@lsu.edu>

#include <iostream>
#include "graph.cpp"

int main(int argc, char **argv) {
  //Declares new graph
  Graph j;
  
  //Accepts a filename as argument and reads the lines.
  //Prints an error message if no argument is provided.
  if (argc != 2)
     std::cout<<"Invalid."<<std::endl;
  else
     j.readLines(std::string(argv[1]));

}
