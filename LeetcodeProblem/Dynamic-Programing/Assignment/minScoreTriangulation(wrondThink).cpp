class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int dp[50][50]={};
        for (int i=A.size()-1;i>=0;i--) {
            for (int j=i+1;j<A.size();j++) {
                for (int k=i+1;k<j;k++) dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],dp[i][k]+A[i]*A[j]*A[k]+dp[k][j]);
            }
        }
        return dp[0][A.size()-1];
    }
};
