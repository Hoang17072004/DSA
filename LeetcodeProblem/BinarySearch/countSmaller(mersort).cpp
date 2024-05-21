void mersort(vector<pair<int,int>> &a,int l,int r,vector<pair<int,int>> &temp,vector<int> &res) {
        if (l<r) {
            int m=(l+r)/2;
            mersort(a,l,m,temp,res);
            mersort(a,m+1,r,temp,res);
            int i=l,j=m+1;
            int less=0;
            int cnt=l;
            while(i<=m&&j<=r) {
                if (a[i].first>a[j].first) {
                    less++;
                    temp[cnt++]=a[j];
                    j++;

                } else {
                    res[a[i].second]+=less;
                    temp[cnt++]=a[i];
                    i++;
                }
            }
            if (i>m) for (int k=j;k<=r;k++) {
                temp[cnt++]=a[k];
            }
            else for (int k=i;k<=m;k++) {
                temp[cnt++]=a[k];
                res[a[k].second]+=less;
            }
            for (int k=l;k<=r;k++) {
                a[k]=temp[k];
            }
           
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> a;
        for (int i=0;i<nums.size();i++) a.push_back({nums[i],i});
        vector<pair<int,int>> b(nums.size());
        vector<int> res(nums.size(),0);
        mersort(a,0,nums.size()-1,b,res);
        return res;
    }
