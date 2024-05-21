class Solution {
public:
    int bfs(vector<vector<int>>&g,vector<bool> &visit,unordered_map<int,unordered_set<int>>& m,int start,int end) {
        queue<int> q;
        for (int x : m[start] ) {
            q.push(x);
        }
        int bus=1;
        while(q.size()) {
            int length=q.size();
            while(length--) {
                int u=q.front();
                q.pop();
                if (m[end].find(u)!=m[end].end()) return bus;
                for (int v: g[u]) {
                    if (!visit[v]) {
                        visit[v]=1;
                        q.push(v);
                    }
                }
            }
            bus++;
        }

        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n=routes.size();
        if (source==target) return 0;
        unordered_map<int,unordered_set<int>> m;
        for (int i=0;i<routes.size();i++) {
            for (int j=0;j<routes[i].size();j++) m[routes[i][j]].insert(i);
        }
        vector<vector<int>> g(n);
        for (int i=0;i<routes.size();i++) {
            for (int j=0;j<routes[i].size();j++) {
                for (int k: m[routes[i][j]]) {
                    if (k==i) continue;
                    g[i].push_back(k);
                }
            }
        }
        vector<bool> visit(n,0);
        return bfs(g,visit,m,source,target);
    }
};
