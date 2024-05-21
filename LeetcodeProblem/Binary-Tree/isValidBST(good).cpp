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
    static const long long min=-1000000000000,max=1000000000000;
    bool isValidBST(TreeNode* root,long long l=min,long long r=max) {
        if(root==nullptr) return true;
        if (root->val>l&&root->val<r) {
            return isValidBST(root->left,l,root->val)&isValidBST(root->right,root->val,r);
        }
        return false;
    }
};
