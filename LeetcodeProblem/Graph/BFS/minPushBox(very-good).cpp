class Solution {
public:
vector<int> moveX={0,0,1,-1};
        vector<int> moveY={1,-1,0,0};
    bool canreach(vector<vector<char>> &grid,int m,int n,pair<int,int> player,pair<int,int> box,pair<int,int> des) {
        queue<pair<int,int>> q;
        set<pair<int,int>> s;
        q.push(player);
        s.insert(player);
        while(q.size()) {
            auto p=q.front();
            q.pop();
            if (p==des) return true;
            for (int i=0;i<4;i++) {
                int x=p.first+moveX[i];
                int y=p.second+moveY[i];
                if (x<0||x==m) continue;
                if (y<0||y==n) continue;
                if (p==box) continue;
                if (grid[x][y]=='#') continue;
                if (s.find({x,y})==s.end()) {
                    s.insert({x,y});
                    q.push({x,y});
                }
            }
        }
        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int sx,sy,bx,by,tx,ty;
        for(int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='S'){
                    sx=i;sy=j;
                } else if (grid[i][j]=='B') {
                    bx=i;by=j;
                } else if (grid[i][j]=='T') {
                    tx=i;ty=j;
                }
            }
        }
        queue<vector<int>> q;
        set<vector<int>> s;
        int push=0;
        q.push({bx,by,sx,sy});
        s.insert({bx,by,sx,sy});
        while(q.size()) {
            int length=q.size();
            while(length--) {
                auto a=q.front();
                int curbx=a[0],curby=a[1],curpx=a[2],curpy=a[3];
                cout<<"["<<curbx<<","<<curby<<","<<curpx<<","<<curpy<<"]\n";
                q.pop();
                if (curbx==tx&&curby==ty) return push;
                for (int i=0;i<4;i++) {
                    int x=curbx+moveX[i];
                    int y=curby+moveY[i];
                    if (x<0||x==m) continue;
                    if (y<0||y==n) continue;
                    if (grid[x][y]=='#') continue;
                    if (s.find({x,y,curbx,curby})==s.end()&&canreach(grid,m,n,{curpx,curpy},{curbx,curby},{curbx-moveX[i],curby-moveY[i]})) {
                        s.insert({x,y,curbx,curby});
                        q.push({x,y,curbx,curby});
                    }
                }
            }
            push++;
        }
        return -1;
    }
};
