#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> MorrisPreorder(TreeNode *root){
    vector<int> ans;
    if(!root) return ans;
    TreeNode* curr = root;
    while(curr){
        if(curr->left){
            TreeNode* prev  = curr->left;
            while(prev->right!=curr && prev->right){
                prev = prev->right;
            }
            if(prev->right == curr){
                prev->right = NULL;
                curr = curr->right;
            }
            else{
                prev->right = curr;
                ans.push_back(curr->val);
                curr = curr->left;
            }

        }
        else{
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}