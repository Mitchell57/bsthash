// main.cpp - Testing and Time-checking of BST and Hash Table implementations
// Mitchell Lewis, Sean Costello

#include <string>
#include <chrono>

int main(){
  auto start = std::chrono::high_resolution_clock::now();
  //any function we want here
  auto stop = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::milli> fp_ms = stop - start;

  
  return 0;
}

float executeTime(void (*function)()){
  

  return stop-start;
}
