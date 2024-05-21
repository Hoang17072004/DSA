long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long l=1,r=0;
        for (int i=0;i<batteries.size();i++) r+=batteries[i];
        r/=n;
        while(l<r) {
            long m=l+(r-l+1)/2;
            long s=0;
            for (int i=0;i<batteries.size();i++) s+=min((long)batteries[i],m);
            if (s>=(long)n*m) l=m; else r=m-1;
        }
        return l;
    }
