int cnt=0;
    void permute(vector<int> &nums,int k) {
        if (k==nums.size()) cnt++;
        for (int i=k;i<nums.size();i++) {
            swap(nums[i],nums[k]);
            if (nums[k]%(k+1)==0||(k+1)%nums[k]==0)permute(nums,k+1);
            swap(nums[i],nums[k]);
        }
    }
    int countArrangement(int n) {
        vector<int> nums(n,0);
        for(int i=1;i<=n;i++) nums[i-1]=i;
        permute(nums,0);
        return cnt;
    }
