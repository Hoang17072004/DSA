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
    int ans=0;
    set<TreeNode*> s;
    int minCameraCover(TreeNode* root) {
        ans=0;
        s.insert(nullptr);
        dfs(root,nullptr);
        return ans;
    }
    void dfs(TreeNode *node,TreeNode *par) {
        if (node!=nullptr) {
            dfs(node->left,node);
            dfs(node->right,node);
            if (par==nullptr&&s.find(node)==s.end()||s.find(node->left)==s.end()||s.find(node->right)==s.end()) {
                ans++;
                s.insert(node);
                s.insert(par);
                s.insert(node->left);
                s.insert(node->right);
            }
        }
    }
};
