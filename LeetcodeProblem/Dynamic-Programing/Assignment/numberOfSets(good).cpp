class Solution {
public:
    int n;
    int memo[1005][1005][2];
    int mod=1e9+7;
    int numberOfSets(int n, int k) {
        this->n=n;
        memset(memo,-1,sizeof(memo));
        return dp(0,k,1);
    }
    int dp(int i,int k,int isStart) {
        if (memo[i][k][isStart]!=-1) return memo[i][k][isStart];
        if (k==0) return 1;
        if (i==n) return 0;
        int ans=dp(i+1,k,isStart);
        if (isStart==1) ans+=dp(i+1,k,0);
        else ans+=dp(i,k-1,1);
        return memo[i][k][isStart]=ans%mod;
    }
};
