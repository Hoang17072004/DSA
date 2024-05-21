int count(vector<int> nums,int bound) {
        int ans=0,cnt=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]>bound) cnt=0; else cnt++;
            ans+=cnt;
        }
        return ans;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums,right)-count(nums,left-1);
    }
