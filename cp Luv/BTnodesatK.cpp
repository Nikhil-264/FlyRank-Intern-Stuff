#include <bits/stdc++.h>
using namespace std;

// This is from ChatGPT
//     Following is the Binary Tree node structure for reference:
template <typename T>
class BinaryTreeNode{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
    }
};

void findNodesAtDistanceK(BinaryTreeNode<int>* root, int k, vector<BinaryTreeNode<int>*>& result) {
    if (!root) return;

    if (k == 0) {
        result.push_back(root);
        return;
    }

    findNodesAtDistanceK(root->left, k - 1, result);
    findNodesAtDistanceK(root->right, k - 1, result);
}

int findTargetNode(BinaryTreeNode<int>* root, int target, int k, vector<BinaryTreeNode<int>*>& result) {
    if (!root) return -1;

    if (root->data == target) {
        findNodesAtDistanceK(root, k, result);
        return 0;
    }

    int leftDist = findTargetNode(root->left, target, k, result);
    if (leftDist != -1) {
        if (leftDist + 1 == k) {
            result.push_back(root);
        } else {
            findNodesAtDistanceK(root->right, k - leftDist - 2, result);
        }
        return leftDist + 1;
    }

    int rightDist = findTargetNode(root->right, target, k, result);
    if (rightDist != -1) {
        if (rightDist + 1 == k) {
            result.push_back(root);
        } else {
            findNodesAtDistanceK(root->left, k - rightDist - 2, result);
        }
        return rightDist + 1;
    }

    return -1;
}

vector<BinaryTreeNode<int>*> distanceK(BinaryTreeNode<int>* root, int target, int k) {
    vector<BinaryTreeNode<int>*> result;
    findTargetNode(root, target, k, result);
    return result;
}


vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    return distanceK(root, target->data, K);
}

int main()
{
        
    return 0;
}