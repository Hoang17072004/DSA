class Solution {
public:
    map<pair<int,int>,bool> mp;
    int get_ans(unordered_map<int,vector<int>> &g,int u,vector<bool> &visit) {
        visit[u]=1;
        int ans=0;
        for (int v: g[u]) {
            if (!visit[v]) {
                ans+=mp.count({u,v}) +get_ans(g,v,visit);
            }
        }
        return ans;
    }
    int res=0;
    void dfs(unordered_map<int,vector<int>> &g,vector<bool> &visit,int k,int u,int ans) {
        if (ans>=k)  res++;
        visit[u]=1;
        for (int v: g[u]) {
            if (!visit[v]) {
                dfs(g,visit,k,v,ans-mp.count({u,v})+mp.count({v,u}));
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        unordered_map<int,vector<int>> m;
        for (auto &e: edges) {
            m[e[0]].push_back(e[1]);
            m[e[1]].push_back(e[0]);
        }
        for (auto &e: guesses) {
            mp[{e[0],e[1]}]=1;
        }
        int n=edges.size()+1;
        vector<bool> visit(n,0);
        int ans=get_ans(m,0,visit);
        visit.assign(n,0);
        dfs(m,visit,k,0,ans);
        return res;
    }
};
