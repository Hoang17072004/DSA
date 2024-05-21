 long long incremovableSubarrayCount(vector<int>& nums) {
        int l=0;
        while(l<nums.size()-1) {
            if (nums[l]<nums[l+1]) l++;
            else break;
        }
        int r=nums.size()-1;
        while (r>0) {
            if (nums[r]>nums[r-1]) r--;
            else break;
        }
        long long res=0;
        int j=r;
        
        for (int i=0;i<=l;i++) {
            while(j<nums.size()&&nums[j]<=nums[i]) j++;
            res+=nums.size()-j;
        }
     
        if (nums.size()==1) return 1;
        if (l>r) return res+nums.size();
        return res+2+l+nums.size()-r;
    }
