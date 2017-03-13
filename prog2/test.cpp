#include <iostream>
#include <vector>

int main() {
  std::vector<char> stuff;
  stuff.push_back('a');
  stuff.push_back('b');
  stuff.pop_back();
  std::cout<<"Printing out vector:";
  for (std::vector<char>::iterator it = stuff.begin(); it != stuff.end(); ++it) {
     std::cout<<" "<<*it;
  }
  std::cout<<std::endl;
}
