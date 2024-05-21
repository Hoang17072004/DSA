class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n=coins.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> cnt(n,0);
        vector<int> q;
        vector<int> steps(n,30000);
        for (int i=0;i<n;i++) {
            cnt[i]=g[i].size();
            if (cnt[i]==1) q.push_back(i);
        }
        while(q.size()) {
            int i=q.back(); q.pop_back();
            if (--steps[i]) {
                n--;
                for (int j: g[i]) {
                    steps[j]=min(steps[j],min(steps[i],coins[i]?2:30000));
                    if(--cnt[j]==1) q.push_back(j);
                }
            }
        }
        return 2*max(0,n-1);
    }
};
