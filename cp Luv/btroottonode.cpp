#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
  int data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;
  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

bool rootToNode(BinaryTreeNode<int> * root, int node, vector<int> &ans){
  if(root == NULL) return false;

  ans.push_back(root->data);

  if(rootToNode(root->left, node, ans) || rootToNode(root->right, node, ans)) return true;

  ans.pop_back();
  return false;
  // rootToNode(root->left, node, ans, a);
  // rootToNode(root->right, node, ans, a);
}

vector<int> rootToNodeVector(BinaryTreeNode<int>* root, int node){
  vector<int> res;
  if(root == NULL) return res;
  rootToNode(root, node, res);
  return res;
}


int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    root ->left = new BinaryTreeNode<int>(2);
    root ->right = new BinaryTreeNode<int>(3);
    root ->left -> left = new BinaryTreeNode<int> (4);
    root ->left ->right = new BinaryTreeNode<int> (5);
    root ->left -> right -> left = new BinaryTreeNode<int> (6);
    root ->left -> right -> right = new BinaryTreeNode<int> (7);
    return 0;
}