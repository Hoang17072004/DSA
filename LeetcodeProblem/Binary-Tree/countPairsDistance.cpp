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
    int cnt=0;
    int res=0;
    vector<int> travel(TreeNode *root,int distance) {
        if (root==nullptr) return vector<int>(distance+1,0);
        if (root->left==nullptr&&root->right==nullptr){
            vector<int> res(distance+1,0);
            res[1]++;
            return res;
        }
        vector<int> left=travel(root->left,distance);
        vector<int> right=travel(root->right,distance);
        for (int l=1;l<distance;l++) {
            for (int r=1;r<distance;r++) {
                if (l+r<=distance) res+=left[l]*right[r];
            }
        }
        vector<int> res(distance+1,0);
        for (int i=1;i<distance;i++) {
            res[i+1]=left[i]+right[i];
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        travel(root,distance);
        return res;
    }
};
