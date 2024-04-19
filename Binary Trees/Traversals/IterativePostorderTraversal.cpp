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


void PostorderTwoStacks(TreeNode *root,vector<int> &ans){
    if(!root) return;
    stack<TreeNode*> st,st2;
    st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        st2.push(node);
        if(root->left) st.push(root->left);
        if(root->right) st.push(root->right);
    }    
    while(!st2.empty()){
        ans.push_back(st.top()->val);
        st.pop();
    }
    return;
}
void PostorderSingleStack(TreeNode *root,vector<int> &ans){
    if(!root) return;
    stack<TreeNode*> st;
    TreeNode *curr = root,*temp;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp = st.top()->right;
            if(!temp){
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else curr = temp;

        }
    }
    return;
}