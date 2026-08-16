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
     int solve(TreeNode* root, int& diameter){
        if(root == nullptr) return 0;
        int left = solve(root->left,diameter);
        int right = solve(root->right,diameter);
        diameter = max(diameter,root->val+left+right);
        return max(0,root->val + max(left,right));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
