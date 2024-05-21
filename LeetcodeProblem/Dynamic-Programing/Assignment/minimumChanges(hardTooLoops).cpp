class Solution {
public:
    int memo[201][201]={},memo_s[201][201],memo_d[201][201];
    int dfs(int i,int k,const string &s) {
        if (i>=s.size()||k<=0) return i==s.size()&&k==0?0:10000;
        if (memo[i][k]==0) {
            memo[i][k]=10000;
            for (int len=2;i+len<=s.size();len++) 
            memo[i][k]=min(memo[i][k],1+memo_s[i][len]+dfs(i+len,k-1,s));
        }
        return memo[i][k]-1;
    }
    int minimumChanges(string s, int k) {
        memset(memo_s,1,sizeof(memo_s));
        for (int d=1;d<=s.size()/2;d++) {
            memset(memo_d,0,sizeof(memo_d));
            for (int len=2*d;len<=s.size();len+=d) {
                for (int i=0;i+len<=s.size();i++) {
                    int ops=0;
                    for (int off=0;off<d;off++) {
                        ops+=s[i+off]!=s[i+len-(d-off)];
                    }
                    memo_d[i][len]=ops+memo_d[i+d][len-2*d];
                    memo_s[i][len]=min(memo_s[i][len],memo_d[i][len]);
                }
            }
        }
        return dfs(0,k,s);
    }
};
