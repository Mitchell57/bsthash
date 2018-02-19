#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "BST.h"
#include "utility.h"

using namespace std;

BST::BST(){
  size = 0;
  head = NULL;
}
BST::BST(string data){
  head = new Node(data, NULL, NULL, 1);
}
bool BST::search(string s, Node* head){
  if (head->getData().compare(s) == 0){
    return true;
  }
  if (head->getLeft() == NULL && head->getRight() == NULL){
    return false;
  }
  if (head->getRight() != NULL){
    if (head->getData().compare(s) <= 0){
      return false || search(s, head->getRight());
    }
  }
  if (head->getLeft() != NULL){
    if (head->getData().compare(s) >= 0){
      return false || search(s, head->getLeft());
    }
  }
  return false;
}

Node* BST::insert(string s, Node* head){
  if (head == NULL){
    size++;
    return new Node(s, NULL, NULL, 1);
  }
  else if (s.compare(head->getData()) == 0){
    head->incrementCount();
  }
  else if (head->getData().compare(s) < 0){
    head->setRight(insert(s,head->getRight()));
  }
  else{
    head->setLeft(insert(s,head->getLeft()));
  }
  return head;
}

Node* BST::del(string s, Node* head){
  if (head == NULL){
    return head;
  }
  if (head->getData().compare(s) == 0){
    if (head->getCount() > 1){
      head->setCount(head->getCount()-1);
    }
    else{
      size--;
      if (head->getLeft() == NULL && head->getRight() == NULL){
	return NULL;
      }
      if (head->getLeft() == NULL && head->getRight() != NULL){
	return head->getRight();
      }
      if (head->getLeft() != NULL && head->getRight() == NULL){
	return head->getLeft();
      }
      else{
	Node* temp = head->getRight();
	if (temp->getLeft() != NULL){
	  while (temp->getLeft()->getLeft() != NULL){
	    temp = temp->getLeft();
	  }
	  head->setData(temp->getLeft()->getData());
	  head->setCount(temp->getLeft()->getCount());
	  temp->setLeft(NULL);
	  return head;
	}
	head->setData(temp->getData());
	head->setCount(temp->getCount());
	head->setRight(NULL);
	return head;
      }
    }
  }
  else if (head->getData().compare(s) < 0){
    head->setRight(del(s,head->getRight()));
  }
  else if (head->getData().compare(s) > 0){
    head->setLeft(del(s,head->getLeft()));
  }
  return head;
}

void BST::print(Node* head){
  if (head != NULL){
    print(head->getLeft());
    cout << head->getData() << " ";
    print(head->getRight());
  }
}

BST::~BST(){
  delB(head);
}

void BST::delB(Node* head){
  if (head != NULL){
    delB(head->getLeft());
    delB(head->getRight());
    delete head;
  }
}

void BST::rangeSearch(string s1, string s2, Node* head){
  if (head == NULL){
    return;
  }
  rangeSearch(s1,s2,head->getLeft());
  if (head->getData().compare(s1) >= 0 && head->getData().compare(s2) <= 0){
    cout << head->getData() << endl;
  }
  rangeSearch(s1, s2, head->getRight());
}

void BST::sort(string path, Node* head){
  ofstream wordsFile;
  wordsFile.open(path);
  string arr [size];
  sortHelper(arr, head, 0);
  for (int i = 0; i < size; i++){
    wordsFile << arr[i] << endl;
  }
  wordsFile.close();
}
void BST::sortHelper(string arr [], Node* head, int c){
  if (head != NULL){
    sortHelper(arr, head->getLeft(),c);
    arr[c] = head->getData();
    sortHelper(arr, head->getRight(),c+1);
  }
} 
