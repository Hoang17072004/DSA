class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,pair<int,int>> m;
        int cnt=1;
        for (int i=n-1;i>=0;i--) {
            if ((n-i)&1) {
                for(int j=0;j<n;j++) {
                    m[cnt++] ={i,j};
                }
            } else for (int j=n-1;j>=0;j--) {
                m[cnt++]={i,j};
            }
        }
        queue<int> q;
        vector<int> d(n*n+1,-1);
        d[1]=0;
        q.push(1);
        while(q.size()) {
            int cur=q.front();
            int x=m[cur].first,y=m[cur].second;
            q.pop();
            for (int next=cur+1;next<=min(cur+6,n*n); next++) {
                auto [row,column]=m[next];
                int destination=grid[row][column]!=-1?grid[row][column]:next;
                if (d[destination]==-1) {
                    d[destination]=d[cur]+1;
                    q.push(destination);
                }
            }
        }
        if (d[n*n]==1000) return -1;
        return d[n*n];
    }
};
