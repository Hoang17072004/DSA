class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        auto compare = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
           return get<0>(a) > get<0>(b);
       };
       priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare)> pq{compare};
        int level=0,trap=0;
        int m=heightMap.size(),n=heightMap[0].size();
        vector<vector<bool>> visit(m,vector<bool>(n,0));
        vector<pair<int,int>> direct={
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        for (int i=0;i<m;i++) {
            visit[i][0]=visit[i][n-1]=1;
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][n-1],i,n-1});
        }
        for (int i=1;i<n-1;i++) {
            visit[0][i]=visit[m-1][i]=1;
            pq.push({heightMap[0][i],0,i});
            pq.push({heightMap[m-1][i],m-1,i});
        }
        while(pq.size()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (h>level) {
                level=h;
            }
            else if (h<level) {
                trap+=level-h;
            }
            for (auto [dx,dy]: direct) {
                dx+=x;
                dy+=y;
                if (dx<0||dx==m||dy<0||dy==n||visit[dx][dy]) continue;
                visit[dx][dy]=1;
                pq.push({heightMap[dx][dy],dx,dy});
            }
        }
        return trap;
    }
};
