 vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size()+1,1);
        vector<int> right(nums.size(),1);
        for (int i=0;i<nums.size();i++) left[i+1]=left[i]*nums[i];
        
        for (int i=nums.size()-2;i>=0;i--) right[i]=right[i+1]*nums[i+1];
        vector<int> res(nums.size());
       
        for (int i=0;i<nums.size();i++) res[i]=left[i]*right[i];
        return res;
    }
