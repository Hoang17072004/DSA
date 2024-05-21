int minOperations(vector<int>& nums) {
        int res=0,maxLen=1;
        for (int a: nums) {
            int bit=0;
            while(a) {
                res+=a&1;
                bit++;
                a>>=1;
            }
            maxLen=max(maxLen,bit);
        }
        return res+maxLen-1;
    }
