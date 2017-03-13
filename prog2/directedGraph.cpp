#include <iostream>
#include <vector>
#include <stdlib.h>
#include "directedGraph.h"

void Directed_graph::add(char x, char y) {
   vertex.push_back(x);
   vertex.push_back(y);
}

void Directed_graph::remove(char x, char y) {
   if(vertex.empty())
       exit(0);
   else {
       std::vector<char> tempVector;
       char tmp;
       while (!vertex.empty()) {
           tmp = vertex.back();
           vertex.pop_back();
           if (tmp != x || tmp != y)
               tempVector.push_back(tmp);
       }
       while (!tempVector.empty()) {
           tmp = tempVector.back();
           tempVector.pop_back();
           vertex.push_back(tmp);
       }
   }
}
/**
void Directed_graph::breadth(char x) {

}

void Directed_graph::depth(char x) {

}
*/
void Directed_graph::print() {
  for(std::vector<char>::iterator it = vertex.begin(); it != vertex.end(); ++it) {
     std::cout<<" "<<*it;
  }
  std::cout<<std::endl;
}
