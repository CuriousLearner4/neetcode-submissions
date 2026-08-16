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
    bool solve(TreeNode* root, int mini, int maxi){
        if(root==nullptr) return true;
        bool left = solve(root->left,mini,root->val);
        bool right = solve(root->right,root->val,maxi);
        return root->val>mini&&root->val<maxi&&left&&right;
    }

public:
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
