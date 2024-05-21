class Solution {
public:
    int mod=1e9+7;
    int dfs(int u,int n,vector<vector<pair<int,int>>> &g,vector<int>&d,vector<int>&memo) {
        if (memo[u]!=-1) return memo[u];
        if (u==n) return 1;
        int ans=0;
        for (auto &e: g[u]) {
            int v=e.first;
            int w=e.second;
            if (d[v]<d[u]) ans=(ans+dfs(v,n,g,d,memo))%mod;
        }
        return memo[u]=ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n+1);
        for (auto &e: edges) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        vector<int> d(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,n});
        d[n]=0;
        while(pq.size()) {
            int u=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            if (dist>d[u]) continue;
            for (auto &e: g[u]) {
                int v=e.first;
                int w=e.second;
                if (d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }
        }
        vector<int> memo(n+1,-1);
        return dfs(1,n,g,d,memo);
    }
};
