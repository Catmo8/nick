// Programming Project 2
// Frank Fontana, III <ffonta2@lsu.edu>

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>

class Graph {
  //Creates a vertex with a key, to see if it is visited, and
  //a vector with the vertex's adjacent vertices.
  class Vertex {
     public:
        char key;
        bool visited;
        std::vector<Vertex*> adj;
        Vertex(char k, bool v) {
           key = k;
           visited = v;
        }
  }; 

public:
  
  std::vector<Vertex*> collection; //Declares a vector filled with vertices
  
  //Search to see if the vertex exist in the collection vector, and
  //returns it.
  Vertex* search(char x) {
     for (int i = 0; i < collection.size(); i++)
        if (collection[i]->key == x)
           return collection[i];
     return NULL; //Returns null if it doesn't exit.
  }
  
  //Adds a new Vertex to the collection vector.
  void add_vertex(char x) {
     if(search(x) == NULL)
        collection.push_back(new Vertex(x, false));
  }
  
  //Adds an edge between an existing or nonexisting vertex to another existing or nonexisting vertex.
  void add_edge(char x, char y) {
     add_vertex(x);
     add_vertex(y);
     
     //Sets a temporary vector equal to the initial vertex and pushes the other vertex into its adjacent vector.
     Vertex* tmp = search(x);
     tmp->adj.push_back(search(y));
  }
  
  //Removes an edge between two existing vertices.
  void remove_edge(char x, char y) {
     Vertex* tmp = search(x);
     if (tmp == NULL) //Prints an error if the vertex isn't found
        std::cout<<"The vertex is not found in the graph."<<std::endl; 
     else {
       //Erases the corresponding vertex in the adjacent vector list.
       for (int i = 0; i < tmp->adj.size(); i++)
           if (tmp->adj[i]->key == y)
              tmp->adj.erase(tmp->adj.begin() + i);
     }
  }
  
  //Marks all Vertices as not visited.
  void unmark_visited() {
     for (int i = 0; i < collection.size(); i++)
        collection[i]->visited = false;
  }

  void breadth(char x) {
     unmark_visited();
     std::queue<Vertex*> q;
     q.push(search(x)); //Search for vertex and then inserts it into the queue.
     while (q.size() != 0) {
        Vertex* v = q.front();
        q.pop();
        v->visited = true; //Removes the vertex from the queue and the vertex visited value is set to true.
        std::cout<<v->key<<" "; //Prints the vertex key.

        //Goes through the adjacent vertex, and if not visited, it is pushed to the queue.
        for(int i = 0; i < v->adj.size(); i++)
           if (v->adj[i]->visited == false)
              q.push(v->adj[i]);
     }
     std::cout<<std::endl;
  }
  
  void depth(char x) {
     unmark_visited();
     std::stack<Vertex*> s;
     s.push(search(x)); //Search for vertex and then inserts it into the stack.
     while (!s.empty()) {
        Vertex* v = s.top();
        s.pop();
        v->visited = true;  //Removes the vertex from the stack and the vertex visited value is set to true.
        std::cout<<v->key<<" "; //Prints the vertex key.
        
        //Goes through the adjacent vertex of the vertex, and if not visited, it is pushed to stack.
        for(int i = 0; i < v->adj.size(); i++)
           if (v->adj[i]->visited == false)
              s.push(v->adj[i]);
     }
     std::cout<<std::endl;
  }
  
  //Reads each individual line from the text file.
  void readLines(std::string fileName) {
     std::fstream file;
     file.open(fileName.c_str());
     std::string buffer; //Declared this string, so I can take it apart later.
     while (std::getline(file, buffer)) {
        std::stringstream ss(buffer);
        std::vector<std::string> token;
        while (ss >> buffer) //Breaks apart the string and stores the parts into the token vector.
           token.push_back(buffer);
        
        //Will check each word in the beginning, and if it isn't one of the words,
        //it does nothing and continues to the next line.
        if (token[0] == "add")
           add_edge(token[1][0], token[2][0]);
    
        else if (token[0] == "remove")
           remove_edge(token[1][0], token[2][0]);

        else if (token[0] == "breadth")
           breadth(token[1][0]);
        
        else if (token[0] == "depth")
           depth(token[1][0]);
        else
           continue;
     }
  }
          
};
