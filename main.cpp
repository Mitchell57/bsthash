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

  HashTable* ht = new HashTable(1000);

  
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
	    cout << "false\n";
	  else
	    cout << "true\n";
	  cout << "Hash: " << execTime.count() << "\n";
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
	  cout << "Hash: " << execTime.count() << "\n";
	  break;
	}

      //delete
      case 3:
	{
	  cout << "3";
	  break;
	}

      //sort
      case 4:
	{
	  cout << "4";
	  break;
	}

      //range sort
    case 5:
      {
        cout << "5";
	break;
      }
    }
  }
    
  
  return 0;
}

