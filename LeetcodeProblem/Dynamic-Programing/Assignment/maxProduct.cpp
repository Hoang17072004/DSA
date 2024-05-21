class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> smallest(n);
        vector<int> largest(n);
        smallest[0]=largest[0]=nums[0];
        for (int i=1;i<n;i++) {
            if (nums[i]>0){
                smallest[i]=min(smallest[i-1]*nums[i],nums[i]);
                largest[i]=max(largest[i-1]*nums[i],nums[i]);
            } else if (nums[i]<0) {
                smallest[i]=min(largest[i-1]*nums[i],nums[i]);
                largest[i]=max(smallest[i-1]*nums[i],nums[i]);
            } else {
                smallest[i]=0;
                largest[i]=0;
            }
        }
        int res=INT_MIN;
        for (int i=0;i<n;i++) res=max(res,largest[i]);
        return res;
    }
};
