// main.cpp - Testing and Time-checking of BST and Hash Table implementations
// Mitchell Lewis, Sean Costello

#include <string>
#include <chrono>
#include <iostream>
#include "HashTable.h"

using namespace std;

int main(){
  auto start = std::chrono::high_resolution_clock::now();
  //any function we want here
  auto stop = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> execTime = stop - start;
  HashTable ht = HashTable(100);
  HashEntry* a = new HashEntry("dog", 5);
  HashEntry* b = new HashEntry("airplane", 5);
  HashEntry* c = new HashEntry("food", 5);
  HashEntry* d = new HashEntry("god", 5);

    
  
  return 0;
}

