class Solution {
public:
    struct cluster{
        set<pair<int,int>> c;
        set<pair<int,int>> uc;
        int wcnt=0;
    };
    void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &visit,cluster &cl) {
        if (i==grid.size()||j==grid[0].size()||i<0||j<0||visit[i][j]||grid[i][j]==-1) return;
        if (grid[i][j]==0) {
            cl.wcnt++;
            cl.uc.insert({i,j});
            return;
        }
        cl.c.insert({i,j});
        visit[i][j]=1;
        dfs(grid,i+1,j,visit,cl);
        dfs(grid,i-1,j,visit,cl);
        dfs(grid,i,j+1,visit,cl);
        dfs(grid,i,j-1,visit,cl);
    }
    int containVirus(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        while(1) {
            vector<vector<bool>> visit(m,vector<bool>(n,0));
            auto comp=[](const cluster &a,const cluster &b) {
                return a.uc.size()<b.uc.size();
            };
            priority_queue<cluster,vector<cluster>,decltype(comp)> pq(comp);
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (grid[i][j]==1&&!visit[i][j]) {
                        cluster c;
                        dfs(grid,i,j,visit,c);
                        pq.push(c);
                    }
                }
            } 
            if (pq.empty()) break;
            cluster k=pq.top();
            pq.pop();
            for (auto x: k.c) {
                grid[x.first][x.second]=-1;
            }
            ans+=k.wcnt;
            while(pq.size()) {
                cluster kq=pq.top();
                pq.pop();
                for (auto x: kq.uc) {
                    grid[x.first][x.second]=1;
                }
            }
        }
        return ans;
    }
};
