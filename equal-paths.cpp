#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
bool checkPaths(Node* node, int currentDep, int& leafDep);

bool equalPaths(Node * root)
{
    int depth = -1;
    return checkPaths(root, 0, depth);
}


bool checkPaths(Node* node, int currDep, int& leafDep){
  if(node == nullptr){
    return true;
  }

  if(node->left == nullptr && node->right == nullptr) {
    if(leafDep == -1){
      leafDep = currDep;
      return true;
    } else{
      return currDep == leafDep;
    }
  }
  return checkPaths(node->left, currDep + 1, leafDep) && checkPaths(node->right, currDep + 1, leafDep);
}

