// binary tree
//  1. create a class for the node of the binary tree

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

void inorder(TreeNode *root, vector<int> &InOrderVector)
{
    if (root == NULL) return;
    else{
        inorder(root->left, InOrderVector);
        InOrderVector.push_back(root->data);
        inorder(root->right, InOrderVector);
    }
}
vector<int> INORDER(TreeNode* root){
    vector<int> result;
    inorder(root, result);
    return result;
}

// Pre- Order Traversal
void preorder(TreeNode * root, vector<int> &PreOrderVector){
    if(root == NULL) return;
    else{
        PreOrderVector.push_back(root->data);
        preorder(root->left, PreOrderVector);
        preorder(root->right, PreOrderVector);
    }
}
vector<int> PREORDER(TreeNode* root){
    vector<int> result;
    preorder(root, result);
    return result;
}

//Post Order Traversal
void postorder(TreeNode * root, vector<int> &PostOrderVector){
    if(root == NULL) return;
    else{
        postorder(root->left, PostOrderVector);
        postorder(root->right, PostOrderVector);
        PostOrderVector.push_back(root->data);
    }
}
vector<int> POSTORDER(TreeNode * root){
    vector<int> result;
    postorder(root, result);
    return result;
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    return {INORDER(root), PREORDER(root), POSTORDER(root)};
}
//make binary tree using struct

vector<vector<int>> levelOrder(TreeNode * root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)  q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
}

//iterative preorder traversal

vector<int>  iterPreorder(TreeNode* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;
    
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        root = s.top();
        s.pop();
        preOrder.push_back(root->data);
        if(root->right != NULL)   s.push(root->right);
        if(root->left != NULL)    s.push(root->left);
    }
    return preOrder;
}

vector<int> iterInOrder(TreeNode * root){
    vector<int> AnsInOrder;
    TreeNode* node = root; 
    stack<TreeNode *> s;
    while(true){
        if(node != NULL){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty()) break;
            node = s.top();
            s.pop();
            AnsInOrder.push_back(node->data);
            node = node->right;
        }
    }
    return AnsInOrder;
}

vector<int> iterPostorder(TreeNode* root){
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* up = st1.top();
        st1.pop();
        st2.push(up);
        if(up->left != NULL){
            st1.push(up->left);
        }
        if(up->right != NULL){
            st1.push(up->right);
        }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

// measuring the tree height
int maxDepth(TreeNode* root) { 
    if(root == NULL) return 0;
    int rh = maxDepth(root->right);
    int lh = maxDepth(root->left);
    return 1 + max(rh, lh); 
} 

// diameter of the tree
int height(TreeNode* root, int& diameter){
    if(!root){
        return 0;
    }
    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

// Maximum path sum
int maxPathDown(TreeNode* node, int & maxi){
    if(node == NULL) return 0;
    int left = max(0, maxPathDown(node->left, maxi));
    int right = max(0, maxPathDown(node->right, maxi));
    maxi = max(maxi, left + right + node-> data);
    return max(left, right) + node->data;
}

int maxPathSum(TreeNode *root) { 
    int maxi =  INT_MIN; 
    maxPathDown(root, maxi);
    return maxi;
}

// Diamter of the tree
int diameterOfBinaryTree(TreeNode*root){
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main()
{
    TreeNode* root  = newNode(50); 
    root->left  = newNode(30);  
    root->right = newNode(70);  
    root->left->left = newNode(20); 
    root->left->right = newNode(10); 
    root->right->left = newNode(90); 
    root->right->right = newNode(100); 

    vector<int> vector1 = iterPreorder(root);
    vector<int> vector2 = iterPostorder(root);
    vector<int> vector3 = POSTORDER(root);
    
    for (int i = 0; i < vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < vector2.size(); i++)
    {
        cout << vector2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < vector3.size(); i++)
    {
        cout << vector3[i] << " ";
    }
    cout << endl;
    
    return 0;
}