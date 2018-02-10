// HashTable.cpp - implementation of hash table for CS130A Project 1
// Mitchell Lewis, 2-8-18

#include <string>
#include <fstream>
#include <iostream>
#include "HashTable.h"

using namespace std;

// Constructor w/ given size
HashTable::HashTable(int inputSize){
  size = 0;
  capacity = (3/2) * inputSize;
  table = new HashEntry*[capacity];
  for(int i=0; i<capacity; i++){
    table[i] = NULL;
  }
}

// Default constructor
HashTable::HashTable(){
  size = 0;
  capacity = 15;
  table = new HashEntry*[capacity];
}

// Destructor
HashTable::~HashTable() {
  for(int i=0; i<capacity; i++){
    if(table[i] != NULL)
      delete table[i];
  }
  delete[] table;
}

// Insert - If entry at hash key is empty, new entry is added
//          If entry at hash key exists and is equal to w, count is incremented
//          If entry at hash key exists and is not equal, uses linear probing to find the next open spot
void HashTable::insert(string w){
  int h = hash(w);
  int probe = h;

  if(table[h] == NULL){
    table[h] = new HashEntry(w, 1);
    size += 1;
    probe = -1;
  }
  else{
    if(table[h]->getWord().compare(w) == 0){
      table[h]->countUp();
      probe = -1;
    }
    else if(probe >= capacity-1)
      probe = 0;
    else
      probe = h+1;
  }

  while(probe != -1 && probe != h){
    if(probe%100 == 0)
      cout << "working...\n";
    if(table[probe] == NULL){
      table[probe] = new HashEntry(w, 1);
      size += 1;
      probe = -1;
    }
    else{
      if(table[probe]->getWord().compare(w) == 0){
	table[probe]->countUp();
	probe = -1;
      }
      else if(probe >= capacity-1)
        probe = 0;
      else
        probe = h+1;
    }
  }
}

// Remove - finds a value in the table, and either decrements the counter, or deletes the value if count = 1
void HashTable::remove(string w){
  int index = search(w);

  if(index == -1)
    return;
  else{
    if(table[index]->getCount() > 1)
      table[index]->countDown();
    else{
      table[index] = NULL;
      size -= 1;
    }
  }
}

void HashTable::sort(string path){
  ofstream wordsFile;
  wordsFile.open(path);
  string sortedWords[size];
  int i, j = 0;
  int flag=1;
  string temp;

  // Put all words into array unsorted
  for(i=0; i<capacity; i++){
    if(table[i] != NULL){
      sortedWords[j] = table[i]->getWord();
      j++;
    }
  }

  //Bubble sort on array of words
  for(i=1; i<=size && flag; i++){
    flag = 0;
    for(j=0; j<size-1; j++){
      if(sortedWords[j+1].compare(sortedWords[j]) < 0){
	temp = sortedWords[j];
	sortedWords[j] = sortedWords[j+1];
	sortedWords[j+1] = temp;
	flag = 1;
      }
    }
  }

  for(i=0; i<size; i++){
    cout << sortedWords[i] << ", ";
    wordsFile << sortedWords[i] << endl;
  }
  cout << endl;
  wordsFile.close();
  
}

// Search - Takes a word as input, checks if it exists at the hash key of that value, then uses linear probing to
// check the rest of the table, with a while loop that terminates after getting back to the initial hash
int HashTable::search(string w){
  int h = hash(w);
  int probe = (h+1)%capacity;
  
  if(table[h] != NULL){
    if(table[h]->getWord().compare(w) == 0)
      return h;
  }

  while(probe != h){
    if(table[probe] != NULL){
      if(table[probe]->getWord().compare(w) == 0)
	return probe;
    }
    if(probe == capacity-1)
      probe = 0;
    else
      probe += 1;
    
  }

  return -1;
}

// Range search - takes two words as input and prints them, as well as every word in the hash table that is
// lexicographically between them
void HashTable::rangeSearch(string w1, string w2){
  cout << w1 << endl;
  for(int i=0; i<capacity; i++){
    if(table[i] != NULL){
      if(table[i]->getWord().compare(w1) > 1 && table[i]->getWord().compare(w2) < 0){
        cout << table[i]->getWord() << endl;
      }
    }
  }
  cout << w2 << endl;
}
  
int HashTable::hash(string word){
  int hash = 0;

  for(unsigned int i=0; i<word.length(); i++){
    hash += (int)word[i] * (33^i);
  }

  return hash%capacity;

}

