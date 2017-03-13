#include <iostream>
#include "directedGraph.h"

int main() {
  Directed_graph *v = new Directed_graph;
  
  v->add('A','B');
  v->add('A','C');
  v->add('B','D');
  v->add('D','E');
  v->add('E','A');
  v->add('E','B');

  //v->breath('A');
  //v->depth('A');

  //v->remove('A','B');
  v->add('B','A');

  //v->breath('B');
  //v->depth('B');

  v->print();
}
