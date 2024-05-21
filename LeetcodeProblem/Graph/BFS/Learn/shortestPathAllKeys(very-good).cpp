class Solution {
public:
    vector<int> moveX={0,0,1,-1};
    vector<int> moveY={1,-1,0,0};
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<vector<int>> q;
        unordered_map<int,set<pair<int,int>>> seen;
        unordered_set<char> keyset;
        unordered_set<char> lockset;
        int allkey=0;
        int sx=0,sy=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='@') {
                    sx=i; sy=j;
                } else if (islower(grid[i][j])) {
                    allkey|=(1<<(grid[i][j]-'a'));
                    keyset.insert(grid[i][j]);
                } else if (isupper(grid[i][j])) lockset.insert(grid[i][j]);
            }
        }
        seen[0].insert({sx,sy});
        q.push({sx,sy,0,0});
        while(q.size()) {
            auto cur=q.front();
            q.pop();
            int x=cur[0],y=cur[1],key=cur[2],d=cur[3];
            for (int i=0;i<4;i++) {
                int u=x+moveX[i],v=y+moveY[i];
                if (u<0||u==m) continue;
                if (v<0||v==n) continue;
                if (grid[u][v]=='#') continue;
                if (islower(grid[u][v])) {
                    if (key&(1<<(grid[u][v]-'a'))) continue;
                    int newkey=key|(1<<(grid[u][v]-'a'));
                    if (newkey==allkey) return d+1;
                    seen[newkey].insert({u,v});
                    q.push({u,v,newkey,d+1});
                }
                if (isupper(grid[u][v])&&!(key&(1<<(grid[u][v]-'A')))) continue;
                else if (seen[key].find({u,v})==seen[key].end()) {
                    seen[key].insert({u,v});
                    q.push({u,v,key,d+1});
                }
            }
        }
        return -1;
    }
};
