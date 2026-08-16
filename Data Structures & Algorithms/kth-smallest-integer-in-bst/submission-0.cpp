/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    void solve(TreeNode* root,int &ans , int& index,int& k){
        if(root==nullptr) return;
        solve(root->left,ans,index,k);
        if(index==k){
            ans = root->val;
        }
        index++;
        solve(root->right,ans,index,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int i = 1;
        solve(root,ans,i,k);
        return ans;
    }
};
