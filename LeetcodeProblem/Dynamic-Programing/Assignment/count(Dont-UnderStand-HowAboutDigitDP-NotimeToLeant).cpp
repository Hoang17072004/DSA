class Solution {
public:
    const int MOD=1e9+7;
    int dp[23][2][2][401];
    int countStrings(int i,bool tight1,bool tight2,int sum,string &num1,string &num2) {
        if (sum<0) return 0;
        if (i==num2.size()) return 1;
        if (dp[i][tight1][tight2][sum]!=-1) return dp[i][tight1][tight2][sum];
        int lo=tight1?num1[i]-'0':0;
        int hi=tight2?num2[i]-'0': 9;
        int count=0;
        for (int idx=lo;idx<=hi;idx++) {
            count=(count%MOD+countStrings(i+1,tight1&(idx==lo),tight2&(idx==hi),sum-idx,num1,num2)%MOD)%MOD;
        }
        return dp[i][tight1][tight2][sum]=count;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int leadingZeroes=num2.length()-num1.length();
        string num1extened=string(leadingZeroes,'0')+num1;
        int total=countStrings(0,1,1,max_sum,num1extened,num2);
        int unnecessary=countStrings(0,1,1,min_sum-1,num1extened,num2);
        int ans=(total-unnecessary+MOD)%MOD;
        return ans;
    }
};
