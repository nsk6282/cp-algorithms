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
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
    return;
}