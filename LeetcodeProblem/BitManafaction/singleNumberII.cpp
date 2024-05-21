vector<int> singleNumber(vector<int>& nums) {
        long diff=0;
        for (int i=0;i<nums.size();i++) diff^=nums[i];
        diff&=(-diff);
        vector<int> res={0,0};
        for (int i=0;i<nums.size();i++) {
            if (nums[i]&diff) res[0]^=nums[i]; 
            else res[1]^=nums[i];
        }
        return res;
    }
