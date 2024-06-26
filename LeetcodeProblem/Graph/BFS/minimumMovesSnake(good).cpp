class Solution {
public:
    bool canRotate(vector<vector<int>>&g,int i,int j) {
        return i<g.size()-1&&j<g[i].size()-1&&(g[i+1][j]&1)==0&&(g[i][j+1]&1)==0&&(g[i+1][j+1]&1)==0;
    }
    bool canGoDown(vector<vector<int>> &g,int i,int j,bool vertical) {
        if (vertical) return i<g.size()-2&&(g[i+2][j]&1)==0;
        return i<g.size()-1&&(g[i+1][j]&1)==0&&(g[i+1][j+1]&1)==0;
    }
    bool canGoRight(vector<vector<int>> &g,int i,int j,bool vertical) {
        if (!vertical) return j<g[i].size()-2&&(g[i][j+2]&1)==0;
        return j<g[i].size()-1&&(g[i][j+1]&1)==0&&(g[i+1][j+1]&1)==0;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        int steps=0;
        queue<vector<int>> q;
        q.push({0,0,false});
        while(q.size()) {
            int length=q.size();
            while(length--) {
                auto &a=q.front();
                if (a[0]==grid.size()-1&&a[1]==grid.size()-2) return steps;
                if ((grid[a[0]][a[1]]&(a[2]?2:4))==0) {
                    grid[a[0]][a[1]]=grid[a[0]][a[1]]|(a[2]?2:4);
                    if (canGoDown(grid,a[0],a[1],a[2])) q.push({a[0]+1,a[1],a[2]});
                    if (canGoRight(grid,a[0],a[1],a[2])) q.push({a[0],a[1]+1,a[2]});
                    if (canRotate(grid,a[0],a[1])) q.push({a[0],a[1],a[2]?false:true});
                }
                q.pop();
            }
            steps++;
        }
        return -1;
    }
};
