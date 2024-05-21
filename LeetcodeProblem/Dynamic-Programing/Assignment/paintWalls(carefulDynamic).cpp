class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        int INF=1e9;
        vector<vector<int>> dp(n+1,vector<int>(n+1,INF));
        for (int i=0;i<=n;i++) dp[i][0]=0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                dp[i][j]=dp[i-1][j];
                // if (j>time[i-1]) {
                    int t=cost[i-1]+dp[i-1][max(j-1-time[i-1],0)];
                    dp[i][j]=min(dp[i][j],t);
                    
                // }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n][n];
    }
};
