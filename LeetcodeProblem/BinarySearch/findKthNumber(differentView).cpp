bool enought(int x,int m,int n,int k) {
        int cnt=0;
        for (int i=1;i<=m;i++) {
            cnt+=min(x/i,n);
        }
        return cnt>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n;
        while(l<r) {
            int mid=(l+r)/2;
            if (enought(mid,m,n,k)) r=mid;
            else l=mid+1;
        }
        return l;
    }
