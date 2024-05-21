class Solution {
public:
    bool isnext(char cur, char nxt) {
        if (cur<'z') return (nxt-cur)==1;
        return nxt=='a';
    }
    int findSubstringInWraproundString(string s) {
        int n=s.size();
        vector<int> dp(26,0);
        for (int i=0;i<n;i++) dp[s[i]-'a']=1;
        int maxlengthcur=0;
        for (int i=0;i<n;i++) {
            if (i&&isnext(s[i-1],s[i])) {
                maxlengthcur++;
            } else maxlengthcur=1;
            int index=s[i]-'a';
            dp[index]=max(dp[index],maxlengthcur);
        }
        int res=0;
        for (int x: dp) res+=x;
        return res;
    }
};
