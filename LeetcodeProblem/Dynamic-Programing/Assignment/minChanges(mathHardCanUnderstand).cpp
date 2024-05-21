class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int freq[k][1025];
        memset(freq,0,sizeof(freq));
        for (int i=0;i<nums.size();i++) freq[i%k][nums[i]]++;
        int dp[k+1][1025];
        for (int i=0;i<=k;i++) for (int j=0;j<1025;j++) dp[i][j]=1e9+5;
        dp[0][0]=0;
        int prevMin=0;
        int n=nums.size();
        for (int i=0;i<k;i++) {
            for (int j=0;j<1025;j++) 
                for (int z=i;z<n;z+=k) 
                    if ((j^nums[z])<1025) 
                        dp[i+1][j^nums[z]]=min(dp[i+1][j^nums[z]],dp[i][j]+int(ceil((n-i)*1.0/k))-freq[i][nums[z]]);
            int prevMin2=1e9+5;
            for (int j=0;j<1025;j++) {
                dp[i+1][j]=min(dp[i+1][j],int(ceil((n-i)*1.0/k)+prevMin));
                prevMin2=min(prevMin2,dp[i+1][j]);
            }
            prevMin=prevMin2;
        }
        return dp[k][0];
    }
};
