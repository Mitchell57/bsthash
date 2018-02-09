
// hashTable.h - defines hash table implementation
// Mitchell Lewis, 2-8-18

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "HashEntry.h"

using namespace std;

class HashTable {
 public:

  // constructor and destructor
  HashTable(int inputSize);
  HashTable();
  
  ~HashTable();
  
  //insert
  void insert(string word, int counter);

  void insert(HashEntry e);
  
  //delete
  void remove(string w);

  //search
  int search(string w);
  
  //sort
  int sort(string w);
  
  //range search
  int rangeSearch(string w1, string w2);

  int hash(string word);
 private:

  int size;
  int capacity;

  HashEntry **table;

};

#endif
