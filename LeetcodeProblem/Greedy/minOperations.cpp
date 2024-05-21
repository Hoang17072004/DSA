int minOperations(vector<int>& nums, int target) {
        long long s=0;
        for (int i=0;i<nums.size();i++) s+=nums[i];
        if (s<target) return -1;
        int res=0;
        sort(nums.begin(),nums.end());
        while(target>0) {
            int a=nums.back();
            nums.pop_back();
            if (s-target>=a) {
                s-=a;
            } else if (a<=target) {
                s-=a;
                target-=a;
            } else {
                nums.push_back(a/2);
                nums.push_back(a/2);
                res++;
            }
        }
        return res;
    }
