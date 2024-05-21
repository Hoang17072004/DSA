 int maxFrequency(vector<int>& nums, int k) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int left=0;
        long cur=0;
        for (int right=0;right<nums.size();right++) {
            cur+=nums[right];
            while((right-left+1)*(long)nums[right]-cur>k) {
                cur-=nums[left];
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
