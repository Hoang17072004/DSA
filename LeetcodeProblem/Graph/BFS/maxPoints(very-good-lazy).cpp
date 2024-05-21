class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> moveX={0,0,1,-1};
        vector<int> moveY={1,-1,0,0};
        int m=grid.size(),n=grid[0].size();
        map<int,int> queryToCount;
        for (int x: queries) {
            queryToCount[x]=0;
        }
        vector<vector<bool>> visit(m,vector<bool>(n,0));
        visit[0][0]=1;
        vector<pair<int,int>> nextBFS;
        nextBFS.push_back({0,0});
        int pre=0;
        for (auto &p: queryToCount) {
            int query=p.first;
            if (grid[0][0]>=query) {
                p.second=0;
                continue;
            }
            int cnt=0;
            queue<pair<int,int>> q;
            for (auto &x: nextBFS) q.push(x);
            nextBFS.clear();
            while(q.size()) {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if (grid[x][y]>=query) {
                    nextBFS.push_back({x,y});
                    continue;
                }
                cnt++;
                for (int i=0;i<4;i++) {
                    int u=x+moveX[i];
                    int v=y+moveY[i];
                    if (u<0||u==m) continue;
                    if (v<0||v==n) continue;
                    if (!visit[u][v]) {
                        visit[u][v]=1;
                        if (grid[u][v]<query) q.push({u,v});
                        else nextBFS.push_back({u,v});
                    }
                }
            }
            p.second=pre+cnt;
            pre+=cnt;
        }
        vector<int> res(queries.size());
        for (int i=0;i<queries.size();i++) {
            res[i]=queryToCount[queries[i]];
        }
        return res;
    }
};
