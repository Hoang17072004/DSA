class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> degree(n,0);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for (int i=0;i<n;i++) if (degree[i]==1) q.push(i);
        vector<int> res;
        while(q.size()) {
            int length=q.size();
            res.clear();
            while(length--) {
                int u=q.front();
                q.pop();
                res.push_back(u);
                for (int v: g[u]) {
                    degree[v]--;
                    if (degree[v]==1) q.push(v);
                }
            }
        }
        if (n==1) return {0};
        return res;
    }
};
