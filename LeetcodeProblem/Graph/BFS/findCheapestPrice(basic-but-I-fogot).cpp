class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        for(auto &f: flights) {
            g[f[0]].push_back({f[1],f[2]});
        }
        queue<vector<int>> pq;
        pq.push({0,src,0});
        vector<int> disc(n,INT_MAX);
        disc[src]=0;
        while(pq.size()) {
            auto &a=pq.front();
            int d=a[0];
            int u=a[1];
            int step=a[2];
            pq.pop();
            if (step>k) continue;
           
            for (auto &e: g[u]) {
                int v=e.first;
                int w=e.second;
                if (disc[v]>d+w) {
                    disc[v]=d+w;
                   pq.push({d+w,v,step+(v!=dst)});
                }

            }
        }
        if(disc[dst]==INT_MAX) return -1;
        return disc[dst];
    }
};
