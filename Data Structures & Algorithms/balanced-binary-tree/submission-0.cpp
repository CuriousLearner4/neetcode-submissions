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
    int helper(TreeNode* root,int& heightDifference){
        if(root==nullptr) return 0;
        int left = helper(root->left,heightDifference);
        int right = helper(root->right,heightDifference);
        heightDifference = max(heightDifference,abs(left-right));
        return 1+max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        int maxHeightDiff = INT_MIN;
        helper(root,maxHeightDiff);
        return maxHeightDiff<=1;
    }
};
