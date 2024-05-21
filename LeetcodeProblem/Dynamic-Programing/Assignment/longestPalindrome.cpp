class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()==1) return s;
        int n=s.size();
        vector<vector<bool>> f(n,vector<bool>(n,0));
        int start=0,length=0;
        for (int i=0;i<n;i++) f[i][i]=true;
        for (int i=0;i<n-1;i++ ) f[i+1][i]=true;
        for (int k=1;k<n;k++) {
            for (int i=0;i<n-k;i++) {
                int j=i+k;
                if (s[i]==s[j]&&f[i+1][j-1]) f[i][j]=true; 
               if (f[i][j]&&length<k) {
                    length=k;
                    start=i;
                }
            }
        }
        return s.substr(start,length+1);
    }
};
