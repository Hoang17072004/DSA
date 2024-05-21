vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        vector<vector<int>> ans;

        for (int i=0;i<nums.size()-2;i++) {
            int sum=-nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if (nums[j]+nums[k]==sum) {
                    res.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                else if (nums[j]+nums[k]>sum) k--;
                else j++;
            }
        }
        while(res.size()>0) {
        ans.push_back(*res.begin());
        res.erase(res.begin());
        }
        return ans;
        
    }
