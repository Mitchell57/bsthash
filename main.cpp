// main.cpp - Testing and Time-checking of BST and Hash Table implementations
// Mitchell Lewis, Sean Costello

#include <string>
#include <chrono>
#include <sstream>
#include <iostream>
#include "HashTable.h"

using namespace std;

int main(){
  /*
  auto start = std::chrono::high_resolution_clock::now();
               any function we want here
  auto stop = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> execTime = stop - start;
  */

  HashTable* ht = new HashTable(100);
  ht->insert("abc");
  ht->insert("dog");
  ht->insert("god");
  ht->insert("airplane");
  ht->insert("grapes");
  ht->insert("monorail");
  ht->insert("get");
  ht->insert("xylophone");
  ht->insert("words");
  ht->insert("airplane");
  
  while(true){
    ostringstream out;
    int choice;
    string  w;
    
    cin >> choice;
    switch(choice){

      //search
      case 1:
	{
	  cin >> w;
	  auto start = std::chrono::high_resolution_clock::now();
          int result = ht->search(w);
          auto stop = std::chrono::high_resolution_clock::now();

	  std::chrono::duration<double, std::milli> execTime = stop - start;
	  if(result == -1)
	    cout << "false" << endl;
	  else
	    cout << "true" << endl;
	  cout << "Hash: " << execTime.count() << endl;
	  break;
	}
	
      //insert
      case 2:
	{
	  cin >> w;
          auto start = std::chrono::high_resolution_clock::now();
          ht->insert(w);
          auto stop = std::chrono::high_resolution_clock::now();

          std::chrono::duration<double, std::milli> execTime = stop - start;
	  cout << "Hash: " << execTime.count() << endl;
	  break;
	}

      //delete
      case 3:
	{
	  cin >> w;
	  auto start = std::chrono::high_resolution_clock::now();
	  ht->remove(w);
	  auto stop = std::chrono::high_resolution_clock::now();

	  std::chrono::duration<double, std::milli> execTime = stop - start;
	  cout << "Hash: " << execTime.count() << endl;
	  break;
	}

      //sort
      case 4:
	{
	  cin >> w;
	  auto start = std::chrono::high_resolution_clock::now();
	  ht->sort(w);
	  auto stop = std::chrono::high_resolution_clock::now();

	  std::chrono::duration<double, std::milli> execTime = stop - start;
	  cout << "Hash: " << execTime.count() << endl;
	  break;
	}

      //range search
    case 5:
      {
        string w2;
	cin >> w;
	cin >> w2;
	auto start = std::chrono::high_resolution_clock::now();
	ht->rangeSearch(w, w2);
	auto stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> execTime = stop-start;
	cout << "Hash: " << execTime.count() << endl;
	break;
      }
    default:
      {
	cin.clear();
	cout << "Invalid input" << endl;
      }
    }
  }
    
  
  return 0;
}

