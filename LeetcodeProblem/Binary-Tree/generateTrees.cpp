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
    vector<TreeNode *> allPossibleBST(int start,int end,map<pair<int,int>,vector<TreeNode*>>&memo) {
        vector<TreeNode*> res;
        if (start>end) {
            res.push_back(nullptr);
            return res;
        }
        if (memo.find({start,end})!=memo.end()) return memo[{start,end}];
        for (int i=start;i<=end;i++) {
            vector<TreeNode*> leftSubTrees=allPossibleBST(start,i-1,memo);
            vector<TreeNode*> rightSubTrees=allPossibleBST(i+1,end,memo);
            for (auto left: leftSubTrees) {
                for (auto right: rightSubTrees) {
                    TreeNode *root=new TreeNode(i,left,right);
                    res.push_back(root);
                }
            }
        }
        memo[{start,end}]=res;
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>,vector<TreeNode*>> memo;
        return allPossibleBST(1,n,memo);
    }
};
