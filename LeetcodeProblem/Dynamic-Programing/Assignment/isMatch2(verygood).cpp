class Solution {
public:
    bool isMatch2 (string s, string p) {
        if (s==""||p=="") return false;
        int m=s.length();
        int n=p.length();
        vector<vector<bool>> M(m+1,vector<bool>(n+1,0));
        M[0][0]=1;
        for (int j=2;j<n+1;j+=2) {
            if (p[j-1]=='*'&&M[0][j-2]) M[0][j]=1;
        }
        for (int i=1;i<m+1;i++) {
            for (int j=1;j<n+1;j++) {
                char curS=s[i-1];
                char curP=p[j-1];
                if (curS==curP||curP=='.') M[i][j]=M[i-1][j-1];
                else if (curP=='*') {
                    char preCurP=p[j-2];
                    if(preCurP!='.'&&preCurP!=curS) M[i][j]=M[i][j-2];
                    else M[i][j]=(M[i][j-2]||M[i-1][j-2]||M[i-1][j]);
                }
            }
        }
        return M[m][n];
    }
};
