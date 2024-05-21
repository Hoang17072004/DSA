int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        int l=nums.size()/2-1,r=nums.size()-1;
        while(l>=0&&r>=0) {
            if (2*nums[l]<=nums[r]) {
                res+=2;
                r--;
            } 
            l--;
        }
        return res;
    }
