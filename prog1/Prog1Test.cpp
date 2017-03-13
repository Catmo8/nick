#include <iostream>
#include <cassert>
#include "PriorityQueue.h"

//The following test functions test whether or not implement class functions work.
void test1(PriorityQueue *q) {
  q->clear();
  q->append('a');
  q->append('b');
  assert (q->size()  == 2);
  assert (q->check() == true);
}

void test2(PriorityQueue *q) {
  q->clear();
  q->append('b');
  q->append('a');
  assert (q->size()  == 2);
  assert (q->check() == false);
}

void test3(PriorityQueue *q) {
  q->clear();
  q->insert('a');
  q->insert('b');
  assert (q->size()   == 2);
  assert (q->check()  == true);
  assert (q->remove() == 'a');
  assert (q->size()   == 1);
}

void test4(PriorityQueue *q) {
  q->clear();
  q->insert('b');
  q->insert('a');
  assert (q->size()   == 2);
  assert (q->check()  == true);
  assert (q->remove() == 'a');
  assert (q->size()   == 1);
}

void test5(PriorityQueue *q) {   //Added an additional test function so I can confirm the correctness
  q->clear();                    //of check() and making sure it doesnt exceed the array.
  q->append('a');
  for (int i = 0; i < 254; i++)
     q->append('b');
  assert (q->size()  == 255);
  assert (q->check() == true);
}

int main() {
  PriorityQueue *q = new PriorityQueue;
  test1(q); //Calling test functions
  test2(q);
  test3(q);
  test4(q);
  test5(q);
}
