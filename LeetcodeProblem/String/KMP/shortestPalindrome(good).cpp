class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string s_new=s+"#"+rev;
        int new_n=s_new.size();
        vector<int> f(new_n,0);
        for (int i=1;i<new_n;i++) {
            int t=f[i-1];
            while(t>0&&s_new[i]!=s_new[t]) t=f[t-1];
            if (s_new[i]==s_new[t]) t++;
            f[i]=t;
        }
        return rev.substr(0,n-f[new_n-1])+s;
    }
};
