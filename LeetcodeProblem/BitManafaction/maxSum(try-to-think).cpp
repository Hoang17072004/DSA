int maxSum(vector<int>& nums, int k) {
       vector<int> count(32,0);
       for (int i=0;i<nums.size();i++) {
           for (int j=0;j<32;j++) {
               if (nums[i]&(1<<j)) count[j]++;
           }
       }
       int mod=1e9+7;
       long long s=0;
       for (int i=0;i<k;i++) {
           int temp=0;
           for (int j=0;j<32;j++) {
               if (count[j]) {
                   count[j]--;
                   temp|=(1<<j);
               }
           }
           s=(s+(long long)temp*temp%mod)%mod;
       }
       return s;
    }
