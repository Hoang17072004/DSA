int totalHammingDistance(vector<int>& nums) {
        int s=0;
        for (int i=0;i<32;i++) {
            int cnt=0;
            for (int j=0;j<nums.size();j++) {
                if (nums[j]&(1<<i)) cnt++;
            }
            s+=cnt*(nums.size()-cnt);
        }
        return s;
    }
