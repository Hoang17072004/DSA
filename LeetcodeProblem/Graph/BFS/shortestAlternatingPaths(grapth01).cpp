class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> blue[n];
        vector<int> red[n];
        for (auto &it: redEdges) {
            red[it[0]].push_back(it[1]);
        }
        for (auto &it: blueEdges) {
            blue[it[0]].push_back(it[1]);
        }
        vector<pair<int,int>> res(n,{INT_MAX,INT_MAX});
        res[0]={0,0};
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        int curdist=0;
        while(q.size()) {
            int length=q.size();
            while(length--) {
                int u=q.front().first;
                int curcol=q.front().second;
                q.pop();
                if (curcol==1) {
                    for (auto &x: blue[u]) {
                        if (res[x].second>curdist+1) {
                            res[x].second=curdist+1;
                            q.push({x,0});
                        }
                    }
                } else {
                    for (auto &x: red[u]) {
                        if (res[x].first>curdist+1) {
                            res[x].first=curdist+1;
                            q.push({x,1});

                        }
                    }
                }
            }
            curdist++;
        }
        vector<int> ans(n,0);
        for (int i=0;i<n;i++) {
            int mini=min(res[i].first,res[i].second);
            if (mini==INT_MAX) ans[i]=-1; else ans[i]=mini;

        }
        return ans;
    }
};
