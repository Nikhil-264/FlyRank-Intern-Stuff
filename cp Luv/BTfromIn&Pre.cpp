// construct the BT from the inorder and preorder tranversal
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x):val(x),right(NULL),left(NULL){}
};

// Binary Tree iterator 
class BSTIterator{
private:
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode * temp = myStack.top();
        myStack.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
private:
    void pushAll(TreeNode * node){
        for(; node != NULL; myStack.push(node), node = node->left);
    }
};

class Solution{
public:
    TreeNode * buildTree(vector<int> & preorder, vector<int>& inorder){
        map<int, int> inMap;

        for (int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }

    TreeNode * buildTree(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, map<int, int> inMap){
        if(preStart > preEnd or inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

};

int main()
{
    
    return 0;
}