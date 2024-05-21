class Solution {
public:
	//The main idea of Toposort is delete node from leaf to root or reverse and affter deleted the left(root) become.. and continue
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> fre(n,0);
        vector<vector<int>> g(n);
        for (int u=0;u<n;u++) {
            for (int v: graph[u]) {
                g[v].push_back(u);
            }
        }
        queue<int> q;
        vector<int> res;
        for (int i=0;i<n;i++) {
            fre[i]=graph[i].size();
            if (fre[i]==0) q.push(i);
        }
        while(q.size()) {
            int u=q.front();
            q.pop();
            res.push_back(u);
            for (int v: g[u]) {
                fre[v]--;
                if (fre[v]==0) q.push(v);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
