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
    unordered_map<int,int> depth;
    unordered_map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> mark;
    int travel(TreeNode *root,int d) {
        if (root==nullptr) return 0;
        depth[root->val]=d;
        int l=travel(root->left,d+1);
        int r=travel(root->right,d+1);
        int h=max(l,r);
        mark[d].push({h,root->val});
        if (mark[d].size()>2) mark[d].pop();
        return h+1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> res;
        travel(root,0);
        for (int i=0;i<queries.size();i++) {
            int d=depth[queries[i]];
            if (mark[d].size()==1) res.push_back(d-1) ;
            else {
                auto one=mark[d].top();
                mark[d].pop();
                auto two=mark[d].top();
                if (two.second==queries[i]) {
                    res.push_back(one.first+d);
                }
                else res.push_back(two.first+d);
                mark[d].push(one);
            }
            
        }
        return res;
    }
};
