class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int m=targetGrid.size(),n=targetGrid[0].size();
        vector<unordered_set<int>> dep(61);
        for (int i=1;i<=60;i++) {
            int minx=m,miny=n,maxx=-1,maxy=-1;
            for (int x=0;x<m;x++) {
                for (int y=0;y<n;y++) {
                    if (targetGrid[x][y]==i) {
                        minx=min(x,minx);
                        miny=min(y,miny);
                        maxx=max(x,maxx);
                        maxy=max(y,maxy);
                    }
                }
            }
            for (int tx=minx;tx<=maxx;tx++) {
                for (int ty=miny;ty<=maxy;ty++) {
                    if (targetGrid[tx][ty]!=i) dep[i].insert(targetGrid[tx][ty]);
                }
            }
        }
        vector<int> vis(61,0);
        for (int i=1;i<=60;i++) if (!vis[i]&&hasCircle(i,dep,vis)) return false;
        return true;
    }
    bool hasCircle(int u,vector<unordered_set<int>>&dep,vector<int>&vis) {
        vis[u]=1;
        for (int v: dep[u]) {
            if (vis[v]==1) return true;
            if (!vis[v]&&hasCircle(v,dep,vis)) return true;
        }
        vis[u]=2;
        return false;
    }
};
