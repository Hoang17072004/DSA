class Solution {
public:
    int n;
    vector<int> moveX={0,0,1,-1};
    vector<int> moveY={1,-1,0,0};
    int dfs(vector<vector<int>>&grid,int x,int y,int index) {
        int area=1;
        grid[x][y]=index;
        for (int i=0;i<4;i++) {
            int u=x+moveX[i];
            int v=y+moveY[i];
            if (u<0||u==n) continue;
            if (v<0||v==n) continue;
            if (grid[u][v]==1) {
                area+=dfs(grid,u,v,index);
            }
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> area;
        n=grid.size();
        int index=2,res=0;
        for (int x=0;x<n;x++) {
            for (int y=0;y<n;y++) {
                if (grid[x][y]==1) {
                    area[index]=dfs(grid,x,y,index);
                    res=max(res,area[index++]);
                }
            }
        }
        for (int x=0;x<n;x++) {
            for (int y=0;y<n;y++) {
                if (grid[x][y]==0) {
                    unordered_set<int> seen;
                    int cur=1;
                    for (int i=0;i<4;i++) {
                        int u=x+moveX[i];
                        int v=y+moveY[i];
                        if (u<0||u==n||v<0||v==n) continue;
                        int idx=grid[u][v];
                        if (idx>1&&seen.count(idx)==0) {
                            seen.insert(idx);
                            cur+=area[idx];
                        }
                    }
                    res=max(res,cur);
                }
            }
        }
        return res;
    }
};
