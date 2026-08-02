// Binary tree vertical traversal in a single vector
// My initial approach
// Use of the map would be better.
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

void traverse(TreeNode<int>* root, int column, int row, vector<pair<pair<int, int>, int>> &mp){
    if (root == NULL) return;
    mp.push_back(make_pair(make_pair(column, row), root->data));
    if(root->left != NULL) traverse(root->left, column - 1, row + 1, mp);
    if(root->right != NULL) traverse(root->right, column + 1, row + 1, mp);
}

vector<int> VerticalTraversal(TreeNode<int>* root){
    vector<int> ans;
    vector<pair<pair<int, int>, int>> mp;
    traverse(root, 0, 0, mp);
    sort(mp.begin(), mp.end());
    for(auto p : mp){
        ans.push_back(p.second);
    }
    return ans;
}

int main()
{
    TreeNode<int>* root =  new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(5);
    vector<int> res = VerticalTraversal(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}