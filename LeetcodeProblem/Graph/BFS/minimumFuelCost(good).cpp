class Solution {
public:
    void countchild(int u,vector<vector<int>> &g,vector<int> &child) {
        child[u]=1;
        for (int v: g[u]) {
            if (child[v]) continue;
            countchild(v,g,child);
            child[u]+=child[v];
        }
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>> g(n);
        for (auto &a: roads) {
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        vector<int> child(n,0);
        vector<bool> visit(n,0);
        countchild(0,g,child);
        queue<int> q;
        q.push(0);
        visit[0]=1;
        long long s=0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            for (int v: g[u]) {
                if (!visit[v]) {
                    s+=child[v]/seats;
                    if (child[v]%seats) s++;
                    visit[v]=1;
                    q.push(v);
                }
            }
        }
        return s;
    }
};
