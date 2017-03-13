#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include <vector>

class Directed_graph {
   private:
       std::vector<char> vertex;

   public:
       void     add(char, char);
       void  remove(char, char);
       void breadth(char);
       void   depth(char);
       void   print();
};

#endif
