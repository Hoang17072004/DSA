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
    unordered_map<int,int> m;
    int target;
    int s=0;
    void Try(TreeNode *root,long long cursum) {
        if (root==nullptr) return;
        cursum+=root->val;
        s+=m[cursum-target];
        m[cursum]++;
        Try(root->left,cursum);
        Try(root->right,cursum);
        m[cursum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        m[0]=1;
        Try(root,0);
        return s;
    }
};
