int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int left=0,maxfre=1;
        int cost=0;
        int med=0;
        for (int right=0;right<nums.size();right++) {
            cost+=nums[right]-nums[med];
            med=(left+right+1)/2;
            while(cost>k) {
                cost-=nums[med]-nums[left];
                left++;
                med=(left+right+1)/2;
            }
            maxfre=max(maxfre,right-left+1);
        }
        return maxfre;
    }
