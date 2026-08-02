#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generate(int n){
    if(n == 0) return vector<TreeNode*>();
    return generateAllBST(1, n);
}

vector<TreeNode*> generateAllBST(int start, int end){

    vector<TreeNode*> allTrees;
    if(start > end){
        allTrees.push_back(NULL);
        return allTrees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode*> leftVector = generateAllBST(start, i - 1);

        vector<TreeNode*> rightVector = generateAllBST(i + 1, end);

        for (int j = 0; j < leftVector.size(); j++){
            for (int k = 0; k < rightVector.size(); k++){
                TreeNode* root = new TreeNode(i);

                root->left = leftVector[j];
                root->right = rightVector[k];
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
    
}

int main()
{
    
    return 0;
}