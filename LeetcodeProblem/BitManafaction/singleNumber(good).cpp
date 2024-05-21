int singleNumber(vector<int>& nums) {
        int ans=0;
        for (int i=0;i<32;i++) {
            int sum=0;
            for (int j=0;j<nums.size();j++) {
                int t=nums[j]>>i&1;
                sum+=t;
            }
            sum%=3;
            ans|=(sum<<i);
        }
        return ans;
    }
