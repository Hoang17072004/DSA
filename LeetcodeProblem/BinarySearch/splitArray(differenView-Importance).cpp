int splitArray(vector<int>& nums, int k) {
        int l=0,r=0;
        for (int i=0;i<nums.size();i++) {
            l=max(l,nums[i]);
            r+=nums[i];
        }
        while(l<r) {
            int m=(l+r)/2;
            int cnt=1,sum=0;
            for (int i=0;i<nums.size();i++) {
                if (sum+nums[i]<=m) {
                    sum+=nums[i];
                } else {
                    sum=nums[i];
                    cnt++;
                }
            }
            if (cnt>k) l=m+1;
            else r=m;

        }
        return r;
    }
