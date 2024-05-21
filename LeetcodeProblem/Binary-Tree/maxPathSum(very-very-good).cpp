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
public:
    int maxvalue;
    int maxPathSum(TreeNode* root) {
        maxvalue=INT_MIN;
        maxPathDown(root);
        return maxvalue;
    }
    int maxPathDown(TreeNode *root) {
        if (root==nullptr) return 0;
        int left=max(0,maxPathDown(root->left));
        int right=max(0,maxPathDown(root->right));
        maxvalue=max(maxvalue,left+right+root->val);
        return max(left,right)+root->val;
    }
};
