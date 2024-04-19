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

void Preorder(TreeNode *root,vector<int> &ans){
    if(!root) return;
    ans.push_back(root->val);
    Preorder(root->left,ans);
    Preorder(root->right,ans);
    return;
}

void Inorder(TreeNode *root,vector<int> &ans){
    if(!root) return;
    Inorder(root->left,ans);
    ans.push_back(root->val);
    Inorder(root->right,ans);
    return;
}

void Postorder(TreeNode *root,vector<int> &ans){
    if(!root) return;
    Postorder(root->left,ans);
    Postorder(root->right,ans);
    ans.push_back(root->val);
    return;
}

