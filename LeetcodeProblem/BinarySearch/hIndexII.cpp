int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0,r=n-1;
        while(l<r) {
            int m=(l+r)/2;
            if (citations[m]<n-m) l=m+1; else r=m;
        }
        if (citations[l]>=n-l) return n-l;
        return 0;
    }
