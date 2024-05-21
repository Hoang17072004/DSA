class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        s="_"+s;
        vector<vector<bool>> a(n+1,vector<bool>(n+1,0));
        for (int i=0;i<=n;i++) a[i][i]=1;
        for (int i=0;i<n;i++) a[i+1][i]=1;
        for (int k=1;k<n;k++) {
            for (int i=1;i<=n-k;i++) {
                int j=i+k;
                a[i][j]=(s[i]==s[j]&&a[i+1][j-1]);
            }
        }
        
        vector<int> b(n+1,INT_MAX);
        for (int i=1;i<=n;i++) {
            if (a[1][i]) {
                b[i]=0;
                continue;
            }
            for (int j=1;j<i;j++) {
                if (a[j+1][i]) b[i]=min(b[i],b[j]+1);
            }
        }
        
        return b[n];
    }
};
