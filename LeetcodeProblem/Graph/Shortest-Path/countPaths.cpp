class Solution {
public:
 
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> g(n);
        for (auto &r: roads) {
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }
        int mod=1e9+7;
        vector<long long> d(n,LONG_MAX);
        d[0]=0;
        vector<long long> fre(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        fre[0]=1;
        while(pq.size()) {
            long long dist=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if (dist>d[u]) continue;
            for (auto &e: g[u]) {
                int v=e.first;
                long long w=e.second;
                if (d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    fre[v]=fre[u];
                    pq.push({d[v],v});
                } else if (d[v]==d[u]+w) fre[v]=(fre[v]+fre[u])%mod;
            }
        }
        return fre[n-1];
    }
};
