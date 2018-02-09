// hashTable.h - defines hash table implementation
// Mitchell Lewis, 2-8-18

#ifndef HASTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

class hashTable {
 public:

  // constructor and destructor
  HashTable(int size);

  ~HashTable();
  
  //insert
  void insert(string word, int counter);

  void insert(node n);
  
  //delete
  void delete(string word);

  //search
  int search(string word);
  
  //sort
  void sort();
  
  //range search
  string[] rangeSearch(string word1, string word2);

  
 private:

  int hash(node n);

  typedef struct node{
    string word;
    int counter;
  }
  
  node table[];

  

  

};
