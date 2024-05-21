class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1]>1&&grid[1][0]>1) return -1;
        int m=grid.size(),n=grid[0].size();
        vector<int> moveX={0,0,1,-1};
        vector<int> moveY={1,-1,0,0};
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        while(pq.size()) {
            auto &a=pq.top();
            int time=a[0];
            int row=a[1];
            int col=a[2];
            pq.pop();
            if (row==m-1&&col==n-1) return time;
            if (visit[row][col]) continue;
            visit[row][col]=1;
            for (int i=0;i<4;i++) {
                int x=row+moveX[i];
                int y=col+moveY[i];
                if (x<0||x==m) continue;
                if (y<0||y==n) continue;
                if (visit[x][y]) continue;
                int wait=(grid[x][y]-time)%2==0;
                pq.push({max(grid[x][y]+wait,time+1),x,y});
            }
        }
        return -1;
    }
};
