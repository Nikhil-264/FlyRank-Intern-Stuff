#include <bits/stdc++.h>
using namespace std;

// template <typename T>
class TreeNode{
public :
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
    }
};

class Solution{
public:
    TreeNode * deleteNode(TreeNode* root, int key){
        if(root == NULL) return NULL;
        if(root->data == key){
            return helper(root);
        }
        TreeNode * dummy = root;
        while(root){
            if(root->data > key){
                if(root->left and root->left->data == key){
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }
            else{
                if(root->right and root->right->data == key){
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return dummy;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode * rightChild = root->right;
        TreeNode * lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }

};

int main()
{
    
    return 0;
}

// MYSolution debug it;
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* cur, int key) {
//         if(cur == NULL) return NULL;
//         TreeNode* root = cur;
//         while(cur){

//             if(cur->val == key){
//                 if(cur->left == NULL and cur->right == NULL){
//                     cur = NULL;
//                     // break;
//                 }
//                 else if(cur->left == NULL){
//                     cur = cur->right;
//                     // break;
//                 }
//                 else if(cur->right == NULL){
//                     cur = cur->left;
//                     // break;
//                 }
//                 else{
//                     TreeNode* temp = cur;
//                     temp = temp->left;
//                     if(temp->right == NULL){
//                         TreeNode* temp1 = cur->right;
//                         cur = cur->left;
//                         cur->right = temp1;
//                     }
//                     while(temp->right->right){
//                         temp = temp->right;
//                     }
//                     cur->val = temp->right->val;
//                     temp->right = NULL;
//                 }
//                 break;
//             }
//             else if(cur->val < key){
//                 cur = cur->right;
//             }
//             else{
//                 cur = cur->left;
//             }

//         }
//         return root;
//     }
// };