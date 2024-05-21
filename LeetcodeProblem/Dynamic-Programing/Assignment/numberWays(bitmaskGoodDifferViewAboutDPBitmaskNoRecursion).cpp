class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int dp[(1<<10)+1][41]={0};
        int mod=1e9+7;
        int n=hats.size();
        unordered_map<int,unordered_set<int>> m;
        for (int i=0;i<n;i++) {
            for (int x: hats[i]) m[x].insert(i);
        }
        for (int i=0;i<=40;i++) dp[0][i]=1;
        for (int mask=1;mask<(1<<n);mask++) {
            for (int i=1;i<=40;i++) {
                dp[mask][i]=dp[mask][i-1];
                for (int j=0;j<n;j++) {
                    if ((mask&(1<<j))&&m[i].find(j)!=m[i].end()) {
                        dp[mask][i]=(dp[mask][i]+dp[mask^(1<<j)][i-1])%mod;
                    }
                }
                
            }
        }
        return dp[(1<<n)-1][40];
    }
};
