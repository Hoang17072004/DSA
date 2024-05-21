int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long res=0;
        int mod=1e9+7;
        vector<int> pow(nums.size(),1);
        for (int i=1;i<nums.size();i++) pow[i]=(pow[i-1]*2)%mod;
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<=j) {
            if(nums[i]+nums[j]<=target) {
                ans=(ans+pow[j-i])%mod;
                i++;
            } else j--;
        }
        return ans;
    }
