 int bestRotation(vector<int>& nums) {
       int n=nums.size();
       vector<int> change(n,0);
       for (int i=0;i<nums.size();i++) change[(i-nums[i]+n+1)%n]--;
       int res=0;
       for (int i=1;i<n;i++) {
           change[i]+=change[i-1]+1;
            if (change[res]<change[i]) res=i;
       }
       return res;

    }
