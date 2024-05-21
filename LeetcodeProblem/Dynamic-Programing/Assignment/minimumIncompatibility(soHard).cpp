class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int n=nums.size(),m=n/k;
        const vector<pair<int,int>> bmap=getMap(nums,m);
        vector<int> dp(1<<n,-1);
        dp[0]=0;
        for (int b=0;b<(1<<n);b++) {
            if (__builtin_popcount(b)%m!=0) continue;
            for (const auto &[tb,v]: bmap) {
                if (tb>b) break;
                if ((tb&b)!=tb) continue;
                if (dp[b-tb]==-1) continue;
                if (dp[b]==-1) dp[b]=dp[b-tb]+v;
                else dp[b]=min(dp[b],dp[b-tb]+v);
            }
        }
        return dp.back();
    }
    vector<pair<int,int>> getMap(const vector<int>&nums,int m) {
        const int n=nums.size();
        vector<pair<int,int>> ans;
        for (int b=0;b<(1<<n);b++) {
            if (__builtin_popcount(b)!=m) continue;
            int vis=0;
            int mx=0,mn=16;
            bool is_good=true;
            for (int i=0;i<n;i++) {
                if ((b&(1<<i))==0) continue;
                if (vis&(1<<nums[i])) {
                    is_good=false;
                    break;
                }
                vis|=(1<<nums[i]);
                mx=max(mx,nums[i]);
                mn=min(mn,nums[i]);
            }
            if (!is_good) continue;
            ans.emplace_back(b,mx-mn);
        }
        return ans;
    }
};
