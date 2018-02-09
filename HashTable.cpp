// HashTable.cpp - implementation of hash table for CS130A Project 1
// Mitchell Lewis, 2-8-18

#include <string>
#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int inputSize){
  size = inputSize;
  capacity = (3/2) * size;
  table = new HashEntry*[capacity];
}

HashTable::HashTable(){
  size = 10;
  capacity = 15;
  table = new HashEntry*[capacity];
}

HashTable::~HashTable() {
  for(int i=0; i<capacity; i++){
    if(table[i] != NULL)
      delete table[i];
  }
  delete[] table;
}

void HashTable::insert(string w){
  int h = hash(w);
  int probe = h;

  if(table[h] == NULL){
    table[h] = new HashEntry(w, 1);
    probe = -1;
  }
  else{
    if(table[h]->getWord().compare(w) == 0){
      table[h]->countUp();
      probe = -1;
    }
    else if(probe == capacity-1)
      probe = 0;
    else
      probe = h+1;
  }

  while(probe != -1 && probe != h){
    if(probe%100 == 0)
      cout << "working...\n";
    if(table[probe] == NULL){
      table[probe] = new HashEntry(w, 1);
      probe = -1;
    }
    else{
      if(table[probe]->getWord().compare(w) == 0){
	table[probe]->countUp();
	probe = -1;
      }
      else if(probe == capacity-1)
        probe = 0;
      else
        probe = h+1;
    }
  }
}

void HashTable::remove(string w){
  int index = search(w);

  if(index == -1)
    return;
  else{
    if(table[index]->getCount() > 1)
      table[index]->countDown();
    else
      table[index] = NULL;
  }
}

int HashTable::sort(string w){
  return 0; //STUB
}

int HashTable::search(string w){
  int h = hash(w);
  int probe = h+1;
  
  if(table[h] != NULL){
    if(table[h]->getWord().compare(w) == 0)
      return h;
  }

  while(probe != h){
    if(table[probe] != NULL){
      if(table[probe]->getWord().compare(w) == 0)
	return probe;
    }
    else{
      if(probe == capacity-1)
	probe = 0;
      else
	probe += 1;
    }
  }

  return -1;
}

int rangeSearch(int w1, int w2){
  return 0; //STUB
}
  
int HashTable::hash(string word){
  int hash = 0;

  for(unsigned int i=0; i<word.length(); i++){
    hash += (int)word[i] * (33^i);
  }

  return hash%capacity;

}

