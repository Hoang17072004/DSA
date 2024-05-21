class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int m=slices.size(),n=m/3;
        vector<int> slices1(slices.begin(),slices.end()-1);
        vector<int> slices2(slices.begin()+1,slices.end());
        return max(helper(slices1,n),helper(slices2,n));
    }
    int helper(vector<int>&nums,int k) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=k;j++) {
                if (i==1) dp[i][j]=nums[0]; else
                dp[i][j]=max(dp[i-1][j],dp[i-2][j-1]+nums[i-1]);
            }
        }
        return dp[n][k];
    }
};
