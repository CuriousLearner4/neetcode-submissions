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
    int solve(TreeNode* root, int maxNode){
        if(root==nullptr) return 0;
        int ans = 0;
        if(maxNode<=root->val){
            ans = 1;
            maxNode = root->val;
        }
        int left = solve(root->left,maxNode);
        int right = solve(root->right,maxNode);
        return ans+left+right;
    }
public:
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};
