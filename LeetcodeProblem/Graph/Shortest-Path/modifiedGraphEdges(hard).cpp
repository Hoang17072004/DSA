class Solution {
public:
    vector<pair<int,int>> g[200];
    int find(int n,int s,int t) {
        vector<int> d(n+1,1e9+10);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,s});
        d[s]=0;
        while(pq.size()) {
            int dist=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if (dist>d[u]) continue;
            for(auto &e:g[u] ) {
                int v=e.first;
                int w=e.second;
                if (d[v]>d[u]+w) {
                    d[v]=d[u]+w;
                    pq.push({d[v],v});
                }
            }
        }
        return d[t];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        for (auto &e: edges) {
            if (e[2]==-1) continue;
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        int t=find(n,source,destination);
        if (t<target) return {};
        if (t==target) {
            for (auto &e: edges) if (e[2]==-1) e[2]=2e9;
            return edges;
        }
        for (int i=0;i<edges.size();i++) {
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if (w==-1) {
                edges[i][2]=1;
                g[u].push_back({v,1});
                g[v].push_back({u,1});
                int t=find(n,source,destination);
                if (t<=target) {
                    edges[i][2]+=target-t;
                    for (int j=i+1;j<edges.size();j++) {
                        if (edges[j][2]==-1) {
                            edges[j][2]=2e9;
                        }
                    }
                    return edges;
                }
            }
        }
        return {};
    }
};
