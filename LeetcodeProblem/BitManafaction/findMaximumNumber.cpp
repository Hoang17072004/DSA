long long pow(int i) {
        return 1LL<<i;
    }
    long long  count(long long n,int x) {
        n++;
        int num=__lg(n)+1;
        long long res=0;
        for (int i=0;i<num;i++) {
            if ((i+1)%x) continue;
            res+=(n/pow(i+1))*pow(i)+max(0LL,n%pow(i+1)-pow(i));
        }
        return res;
    }
    long long findMaximumNumber(long long k, int x) {
        long long l=0,r=1e15;
        while(l<r) {
            long long m=l+(r-l+1)/2;
            if (count(m,x)<=k) l=m; else r=m-1;
        }
        return l;
    }
