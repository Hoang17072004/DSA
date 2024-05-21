class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(33,0);
        dp[0]=1;
        dp[1]=2;
        for (int i=2;i<=32;i++) dp[i]=dp[i-1]+dp[i-2];
        int res=0;
        int lastBit=-1;
        for (int i=31;i>=0;i--) {
            if (n&(1<<i)) {
                res+=dp[i];
                if (lastBit==1) return res;
            }
            lastBit=(n>>i)&1;
        }
        return res+1;
    }
};
