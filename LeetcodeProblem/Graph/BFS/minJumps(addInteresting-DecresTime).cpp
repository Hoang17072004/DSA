class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> g;
        for (int i=0;i<arr.size();i++) g[arr[i]].push_back(i);
        queue<int> q;
        vector<bool> visit(n,0);
        visit[0]=1;
        q.push(0);
        vector<int> move={1,-1};
        vector<int> d(n,0);
        if (n==1) return 0;
        while(q.size()) {
            int u=q.front();
            q.pop();
            for (int i=0;i<2;i++) {
                int v=u+move[i];
                if (v<0||v==n) continue;
                if (!visit[v]) {
                    q.push(v);
                    visit[v]=1;
                    d[v]=d[u]+1;
                    if (v==n-1) return d[v];
                }
            }
            for (int v: g[arr[u]]) {
                if (v==u) continue;
                if(!visit[v]) {
                    visit[v]=1;
                    q.push(v);
                    d[v]=d[u]+1;
                    if (v==n-1) return d[v];
                }
            }
            g[arr[u]].clear();
        }

        return -1;
    }
};
