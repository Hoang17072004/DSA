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
    TreeNode *helper(int k,int start,int end, vector<int> &preorder,vector<int>&inorder,unordered_map<int,int>&m) {
        if (start>end) return nullptr;
        int idx=m[preorder[k]];
        TreeNode *left=helper(k+1,start,idx-1,preorder,inorder,m);
        TreeNode *right=helper(k+idx-start+1,idx+1,end,preorder,inorder,m);
        TreeNode *root=new TreeNode(preorder[k],left,right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for (int i=0;i<inorder.size();i++) m[inorder[i]]=i;
        return helper(0,0,inorder.size()-1,preorder,inorder,m);
    }
};
