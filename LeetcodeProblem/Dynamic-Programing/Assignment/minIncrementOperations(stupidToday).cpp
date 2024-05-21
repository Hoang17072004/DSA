class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> dp(n,0);
        for (int i=0;i<n;i++) {
            if (i<3) dp[i]=max(k-nums[i],0);
            else dp[i]=max(k-nums[i],0)+min({dp[i-1],dp[i-2],dp[i-3]});
        }
        long long res=LONG_MAX;
        for (int i=n-1;i>=n-3;i--) res=min(res,dp[i]);
        return res;
    }
};
