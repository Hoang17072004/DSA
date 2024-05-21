class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        vector<int> d(n,maxMoves+1);
        d[0]=0;
        vector<bool> visit(n,0);
        pq.push({0,0});
        map<pair<int,int>,int> used;
        int ans=0;
        while(pq.size()) {
            int u=pq.top().second;
         
            pq.pop();
            if (visit[u]) continue;
            visit[u]=1;
            ans++;
            for (auto &e: g[u]) {
                int v=e.first;
                int w=e.second;
                used[{u,v}]=min(w,maxMoves-d[u]);
                if (min(d[v],maxMoves+1)>d[u]+w+1) {
                    d[v]=d[u]+w+1;
                    pq.push({d[v],v});
                }
            }
        }
        for (auto &e: edges) {
            int u=e[0],v=e[1],w=e[2];
            ans+=min(w,used[{u,v}]+used[{v,u}]);
        }
        return ans;
    }
};
