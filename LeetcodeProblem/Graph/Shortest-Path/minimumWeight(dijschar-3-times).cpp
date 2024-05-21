class Solution {
public:

    void dijscha(vector<vector<pair<int,int>>> &g,vector<long> &d,int s,int n) {
        d.assign(n,LONG_MAX);
        d[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        while(q.size()) {
            int u=q.top().second;
            int dist=q.top().first;
            q.pop();
            if (dist>d[u]) continue;
            for (auto &e: g[u]) {
                int v=e.first;
                int w=e.second;
                if (d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    q.push({d[v],v});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> g(n);
        vector<vector<pair<int,int>>> r(n);
        for (auto &e: edges) {
            g[e[0]].push_back({e[1],e[2]});
            r[e[1]].push_back({e[0],e[2]});
        }
        vector<long> d1(n);
        vector<long> d2(n);
        vector<long> dd(n);
        dijscha(g,d1,src1,n);
        
        dijscha(g,d2,src2,n);
        dijscha(r,dd,dest,n);
        long res=LONG_MAX;
        for (int i=0;i<n;i++) {
            if (d1[i]==LONG_MAX||d2[i]==LONG_MAX||dd[i]==LONG_MAX) continue;
            res=min(res,d1[i]+d2[i]+dd[i]);
        }
        if (res==LONG_MAX) return -1;
        return res;
    }
};
