class Solution {
public:
    void dfs(vector<vector<int>> &g,vector<int> &nums,vector<bool> &visit,int u) {
        if(visit[nums[u]]) return;
        for (int v: g[u]) {
            dfs(g,nums,visit,v);
        }
        visit[nums[u]]=1;
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n=parents.size();
        vector<int> res(n,1);
        vector<bool>visit(100010,0);
        auto it=find(nums.begin(),nums.end(),1);
        if (it==nums.end()) return res;
        vector<vector<int>> g(n);
        for (int i=1;i<n;i++) g[parents[i]].push_back(i);
        int i=it-nums.begin(),miss=1;
        while(i>-1) {
            dfs(g,nums,visit,i);
            while(visit[miss]) {
                miss++;
            }
            res[i]=miss;
            i=parents[i];
        }
        return res;
    }
};
