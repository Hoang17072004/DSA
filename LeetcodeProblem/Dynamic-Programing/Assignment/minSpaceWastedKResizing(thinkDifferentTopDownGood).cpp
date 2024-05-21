class Solution {
public:
    int dp[201][201]={[0 ... 200][0 ... 200]=-1};
    int dfs(vector<int>&nums,int i,int k) {
        if (i+k>=nums.size()) return 0;
        if (k<0) return 1000000000;
        if (dp[i][k]==-1) {
            dp[i][k]=dfs(nums,i+1,k-1);
            int mx=nums[i],sum=nums[i];
            for (int j=i+1;j<nums.size();j++) {
                mx=max(mx,nums[j]);
                sum+=nums[j];
                int diff=mx*(j-i+1)-sum;
                dp[i][k]=min(dp[i][k],diff+dfs(nums,j+1,k-1));
            }

        }
        return dp[i][k];
    }
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        return dfs(nums,0,k+1);
    }
};
