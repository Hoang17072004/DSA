class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        for (int i=n-2;i>=0;i--) {
            if (nums[i]>nums[i+1]) {
                int t=nums[i]/nums[i+1];
                if (nums[i]%nums[i+1]) t++;
                nums[i]=nums[i]/t;
                res+=t-1;
            }
        }
        return res;
    }
};
