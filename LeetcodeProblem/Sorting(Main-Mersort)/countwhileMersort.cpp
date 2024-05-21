int countwhileMersort(vector<long long> &a,int l,int r,vector<long long> &b,int lower,int upper){
        if (l>=r) return 0;
        int m=(l+r)/2;
        int count=countwhileMersort(a,l,m,b,lower,upper)+countwhileMersort(a,m+1,r,b,lower,upper);
        int j=m+1,k=m+1,h=m+1;
        int cnt=l;
        for (int i=l;i<=m;i++) {
            while(j<=r&&a[j]-a[i]<lower) j++;
            while(k<=r&&a[k]-a[i]<=upper) k++;
            while(h<=r&&a[h]<a[i]) {
                b[cnt]=a[h];
                cnt++; h++;
            }
            b[cnt++]=a[i];
            count+=k-j;
        }
        for (int i=l;i<cnt;i++) a[i]=b[i];
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size()+1,0);
        for (int i=0;i<nums.size();i++) prefix[i+1]=prefix[i]+nums[i];
        vector<long long> temp(nums.size()+1,0);
        return countwhileMersort(prefix,0,nums.size(),temp,lower,upper);

    }
