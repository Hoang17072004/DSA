class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+3,vector<int>(n+3,0));
        for (int length=1;length<n;length++) {
            for (int i=1;i<=n-length;i++) {
                int j=i+length;
                dp[i][j]=INT_MAX;
                for (int k=i;k<=j;k++) {
                    dp[i][j]=min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]));
                }
            }
        }
        
        return dp[1][n];
    }
};
