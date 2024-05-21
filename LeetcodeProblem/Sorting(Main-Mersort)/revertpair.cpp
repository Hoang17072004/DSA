int solveWhileMersort(vector<int> &a,int l,int r,vector<int> &b) {
        if (l>=r) return 0;
        int m=(l+r)/2;
        int count=solveWhileMersort(a,l,m,b)+solveWhileMersort(a,m+1,r,b);
        int i=l,j=m+1;
        int cnt=l;
        int k=m+1;
        while(i<=m||j<=r) {
            while(k<=r&&(long long)a[i]>2*(long long)a[k]) k++;
            if (i<=m&j<=r) {

                if (a[i]<a[j]) {
                    b[cnt++]=a[i];
                    count+=k-m-1;
                    i++;
                }  else {
                    b[cnt++]=a[j];
                    j++;
                }
            } else if (i<=m) {
                b[cnt++]=a[i];
                count+=k-m-1;
                i++;
            } else if (j<=r) {
                b[cnt++]=a[j];
                j++;
            }
        }
        for (int h=l;h<=r;h++) a[h]=b[h];
       return count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> b(nums.size(),0);
        return solveWhileMersort(nums,0,nums.size()-1,b);
    }
