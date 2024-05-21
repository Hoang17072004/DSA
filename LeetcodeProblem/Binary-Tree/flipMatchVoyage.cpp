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
    vector<int> flipped;
    int index=0;
    vector<int> voyage;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        this->voyage=voyage;
        dfs(root);
        if (flipped.size()&&flipped[0]==-1) {
            return {-1};
        }
        return flipped;
    }
    void dfs(TreeNode *root) {
        if (root==nullptr) return;
        if (root->val!=voyage[index++]) {
            flipped.clear();
            flipped.push_back(-1);
            return;
        }
        if (index<voyage.size()&&root->left!=nullptr&&root->left->val!=voyage[index] ) {
            flipped.push_back(root->val);
            dfs(root->right);
            dfs(root->left); 
        } else {
            dfs(root->left);
            dfs(root->right);
        }
    }
};
