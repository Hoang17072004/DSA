int sumOfFlooredPairs(vector<int>& nums) {
        const int MAX=1e5;
        const int MOD=1e9+7;
        int count[MAX+2]={0};
        for (int i=0;i<nums.size();i++) count[nums[i]]++;
        for (int i=1;i<=MAX;i++) count[i]+=count[i-1];
        long long res=0;
        for (int i=1;i<=MAX;i++) {
            if (count[i]>count[i-1]) {
                long long sum=0;
                for (int j=1;j*i<=MAX;j++) {
                    int lower=i*j-1;
                    int upper=i*(j+1)-1;
                    sum+=(count[min(upper,MAX)]-count[lower])*(long long)j;
                }
                res+=(sum)*(count[i]-count[i-1]);
                //res%=MOD;
            }
        }
        return res%MOD;
    }
