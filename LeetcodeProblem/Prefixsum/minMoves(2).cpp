 int minMoves(vector<int>& nums, int k) {
        vector<int> index;
        for (int i=0;i<nums.size();i++) if (nums[i]) index.push_back(i);
        vector<long long> prefix(index.size()+1,0);
        for (int i=0;i<index.size();i++) prefix[i+1]=prefix[i]+index[i];
        int res=INT_MAX;
        if (k%2==1) {
            for (int i=0;i<=index.size()-k;i++) {
                int l=i,r=i+k-1;
                int m=(l+r)/2;
                int radius=(k-1)/2;
                int value=(prefix[i+k]-prefix[m+1])-(prefix[m]-prefix[l])-(radius+1)*radius;
                res=min(res,value);
            }
        } else {
            for (int i=0;i<=index.size()-k;i++) {
                 int l=i,r=i+k-1;
                int m=(l+r)/2;
                int radius=(k-2)/2;
                int value=(prefix[i+k]-prefix[m+1])-(prefix[m]-prefix[l])-(radius+1)*radius-index[m]-(radius+1);
                res=min(res,value);
            }
        }
        return res;
    }
