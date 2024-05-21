class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long dp[2000001]={0};
        for (int i=questions.size()-1;i>=0;i--) dp[i]=max(dp[i+1],dp[i+questions[i][1]+1]+questions[i][0]);
        return dp[0];
    }
};
