vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> prefix(nums.size()+1,0);
        for (int i=0;i<nums.size();i++) prefix[i+1]=prefix[i]+nums[i];
        vector<int> res(nums.size(),0);
        for (int i=0;i<nums.size();i++) res[i]=i*nums[i]-prefix[i]-(nums.size()-1-i)*nums[i]+(prefix[nums.size()]-prefix[i+1]);
        return res;
        
    }
