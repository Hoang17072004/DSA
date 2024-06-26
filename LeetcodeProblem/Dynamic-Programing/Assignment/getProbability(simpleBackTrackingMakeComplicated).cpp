class Solution {
public:
    double perm(vector<int>&A) {
        double ans=1;
        for (int i=0,j=1;i<A.size();i++) {
            for (int k=1;k<=A[i];k++,j++) ans=ans*j/k;
        }
        return ans;
    }
    int sum=0;
    double dfs(vector<int>&A,vector<int>&a,vector<int>&b,int i,int sa,int sb) {
        if (sa>sum/2||sb>sum/2) return 0;
        if (i==A.size()) {
            int ca=0,cb=0;
            for (int j=0;j<A.size();j++) ca+=a[j]>0;
            for (int j=0;j<A.size();j++) cb+=b[j]>0;
            if (ca!=cb) return 0;
            return perm(a)*perm(b);
        }
        double ans=0;
        for (int j=0;j<=A[i];j++) {
            a[i]=j;
            b[i]=A[i]-j;
            ans+=dfs(A,a,b,i+1,sa+a[i],sb+b[i]);
        }
        return ans;
    }
    double getProbability(vector<int>& A) {
        sum=accumulate(begin(A),end(A),0);
        vector<int> a(A.size()),b(A.size());
        return dfs(A,a,b,0,0,0)/perm(A);
    }
};
