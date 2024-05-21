class Solution {
public:
    int numPermsDISequence(string s) {
        int n=s.length(),mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for (int j=0;j<=n;j++) dp[0][j]=1;
        for (int i=0;i<n;i++) {
            if (s[i]=='I') for (int j=0,cur=0;j<n-i;j++) dp[i+1][j]=cur=(cur+dp[i][j])%mod;
            else for (int j=n-1-i,cur=0;j>=0;j--) dp[i+1][j]=cur=(cur+dp[i][j+1])%mod;
        }
        return dp[n][0];
    }
};
