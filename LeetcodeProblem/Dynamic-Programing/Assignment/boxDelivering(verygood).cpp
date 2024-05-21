class Solution {
public:
    int boxDelivering(vector<vector<int>>& A, int portsCount, int B, int W) {
        int n=A.size(),need=0,j=0,lastj=0;
        vector<int> dp(n+1,200000);
        dp[0]=0;
        for (int i=0;i<n;i++) {
            while(j<n&&B>0&&W>=A[j][1]) {
                B-=1;
                W-=A[j][1];
                if (j==0||A[j][0]!=A[j-1][0]) {
                    lastj=j;
                    need++;
                }
                j++;
            }
            dp[j]=min(dp[j],dp[i]+need+1);
            dp[lastj]=min(dp[lastj],dp[i]+need);
            B+=1;
            W+=A[i][1];
            if (i==n-1||A[i][0]!=A[i+1][0]) need--;
        }
        return dp[n];
    }
};
