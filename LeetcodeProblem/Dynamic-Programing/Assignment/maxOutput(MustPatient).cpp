class Solution {
public:
    vector<long long> subtree_sum;
    long long max_diff=0;
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> tree(n);
        for (auto &e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        subtree_sum=vector<long long> (n,0);
        dfs(0,-1,tree,price);
        dfs2(0,-1,tree,price,0);
        return max_diff;
    }
    long long dfs(int node,int parent,vector<vector<int>>&tree,vector<int>&price) {
        long long  m =0;
        for (int child: tree[node]) {
            if (child==parent) continue;
            m=max(m,dfs(child,node,tree,price));
        }
        return subtree_sum[node]=price[node]+m;
    }
    void dfs2(int node,int parent,vector<vector<int>>&tree,vector<int>&price,long long parent_contribution ) {
        int c1=-1;
        long long mc1=0,mc2=0;
        for (int child: tree[node]) {
            if (child==parent) continue;
            if (subtree_sum[child]>mc1) {
                mc2=mc1;
                mc1=subtree_sum[child];
                c1=child;
            } else if (subtree_sum[child]>mc2) {
                mc2=subtree_sum[child];
            }
        }
        long long path1=mc1;
        long long path2=parent_contribution;
        max_diff=max(max_diff,max(path1,path2));
        for (int child: tree[node]) {
            if (child==parent) continue;
            if (child==c1) dfs2(child,node,tree,price,price[node]+max(parent_contribution,mc2));
            else dfs2(child,node,tree,price,price[node]+max(mc1,parent_contribution));
        }
    }
};
