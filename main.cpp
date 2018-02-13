// main.cpp - Testing and Time-checking of BST and Hash Table implementations
// Mitchell Lewis, Sean Costello

#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include "HashTable.h"

using namespace std;

// Read_directory - writes filenames inside a given directory to a string vector
void read_directory(const string& name, vector<string>* v){
  DIR* dirp = opendir(name.c_str());
  struct dirent * dp;
  while((dp = readdir(dirp)) != NULL){
    // adds name of entry to list as long as it does not start with a '.'
    if((dp->d_name)[0] != '.'){
      v->push_back(dp->d_name);
    }
  }
  closedir(dirp);
}

void parse_text(const string& name, vector<string>* v){
  ifstream inFile(name);
  string str;

  while(inFile >> str){
    

    //v->push_back(str);
  }

  inFile.close();
}

int main(){

  //Text parsing
  vector<string> filenames, dirnames;
  string root = "hotels-small";

  // retrieves subdirectory names
  read_directory(root, &dirnames);

  // retrieves filenames inside each subdirectory, then builds the path up to the main dataset folder, then adds
  // to filename list
  for(unsigned int i=0; i<dirnames.size(); i++){
    vector<string> tempFileNames;
    string subdir = root + "/" + dirnames.at(i);
    read_directory(subdir, &tempFileNames);
    for(unsigned int j=0; j<tempFileNames.size(); j++){
      
      string path = subdir + "/" + tempFileNames.at(j);
      filenames.push_back(path);
    }
  }

  vector<string> rawData;
  parse_text(filenames.at(0), &rawData);

  
  HashTable* ht = new HashTable(10);

  // Test interface - Prompts input for 1-5, performs search, insert, remove, sort, and range search respectively
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

      //remove
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
	cin.ignore(10000, '\n');
	cout << "Invalid input" << endl;
      }
    }
  }
    
  
  return 0;
}


