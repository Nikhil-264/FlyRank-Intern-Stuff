// Boundary traversal 
// anticlockwise
// BT

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

bool isLeaf(TreeNode*root){
    return  !(root->left || root->right);
}

void addLeftBoundary(TreeNode* root, vector<int> &res){
    TreeNode*cur = root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightboundary(TreeNode * root, vector<int> &res){
    TreeNode* cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
}

void addLeaves(TreeNode*root, vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return ;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightboundary(root, res);
    return res;
}

int main()
{
    
    return 0;
}