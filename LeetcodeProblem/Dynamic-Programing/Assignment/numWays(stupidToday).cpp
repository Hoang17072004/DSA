class Solution {
public:
    int numWays(int steps, int arrLen) {
        int maxPos=min(steps,arrLen);
        vector<vector<long long>> dp(steps+1,vector<long long>(maxPos+1));
        dp[1][0]=1;
        dp[1][1]=1;
        int mod=1e9+7;
        for (int i=2;i<=steps;i++) {
            for (int j=0;j<maxPos;j++) {
                dp[i][j]=(dp[i-1][j]+dp[i-1][j+1]+(j>0?dp[i-1][j-1]:0))%mod;
            }
        }
        return dp[steps][0];
    }
};
