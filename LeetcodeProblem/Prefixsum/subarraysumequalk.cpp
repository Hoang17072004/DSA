int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> prefix(nums.size()+1,0);
        m[0]=1;
        int cnt=0;
        for (int i=0;i<nums.size();i++) {
            prefix[i+1]=prefix[i]+nums[i];
             if (m[prefix[i+1]-k]) cnt+=m[prefix[i+1]-k];
            m[prefix[i+1]]++;
            
        }
        
        
        return cnt;
    }
