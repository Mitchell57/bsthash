#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Node
{
 private:
  int counter;
  Node* left;
  Node* right;
  string data;
 public:
  Node(string data, Node* left, Node* right, int counter){
    this->data = data;
    this->left = left;
    this->right = right;
    this->counter = counter;
  }
  int getCounter(){
    return counter;
  }
  Node* getLeft(){
    return left;
  }
  Node* getRight(){
    return right;
  }
  string getData(){
    return data;
  }
  void setLeft(Node* n){
    left = n;
  }
  void setRight(Node* n){
    right = n;
  }
  void setData(string s){
    data = s;
  }
  void incrementCount(){
    counter++;
  }
  void setCount(int c){
    counter = c;
  }
  int getCount(){
    return counter;
  }
};


#endif
