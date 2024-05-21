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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr) return root;
        if (key<root->val) {
            root->left= deleteNode(root->left,key);
            return root;
        }
        else if (key>root->val) {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else {
            if (root->left==nullptr) {
                TreeNode *temp=root->right;
                delete root;
                return temp;
            }
            else if (root->right==nullptr) {
                TreeNode *temp=root->left;
                delete root;
                return temp;
            }
            else {
                TreeNode *sucparent=root;
                TreeNode *suc=root->right;
                while(suc->left!=nullptr) {
                    sucparent=suc;
                    suc=suc->left;
                }
                if (sucparent!=root) {
                    sucparent->left=suc->right;
                } else sucparent->right=suc->right;
                root->val=suc->val;
                delete suc;
                return root;
            }
        }
    }
};
