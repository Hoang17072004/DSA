class Solution {
public:
    int MOD=1e9+7;
    int countSubMultisets(vector<int>& nums, int l, int r) {
        unordered_map<int,int> mp;
        for (int num: nums) {
            mp[num]++;
        }
        vector<long long> dp(r+1,0);
        dp[0]=1;
        for (auto e: mp) {
            int num=e.first;
            int freq=e.second;
            vector<long long> pSum=dp;
            for (int i=0;i<=r;i++) {
                if (i>=num) pSum[i]=(pSum[i]+pSum[i-num])%MOD;
            }
            for (int i=r;i>=0;i--) {
                if (num>0) {
                    int j=i-(freq+1)*num;
                    dp[i]=pSum[i]-(j>=0?pSum[j]:0);
                    dp[i]=(dp[i]+MOD)%MOD;
                } else {
                    dp[i]*=freq+1;
                    dp[i]%=MOD;
                }
            }
        }
        long long res=0;
        for (int i=l;i<=r;i++) res=(res+dp[i])%MOD;
        return res;
    }
};
