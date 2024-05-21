int  (vector<int>& arr) {
        vector<vector<int>> a;
        int n=arr.size();
        
        map<int,int> index;
        for (int i=0;i<n;i++) index[arr[i]]=i;
        map<int,int> longest;
        int res=0;
        for (int k=0;k<n;k++) {
            for (int j=0;j<k;j++) {
                if (arr[k]-arr[j]<arr[j]&&index.count(arr[k]-arr[j])) {
                    int i=index[arr[k]-arr[j]];
                    longest[j*n+k]=longest[i*n+j]+1;
                    res=max(res,longest[j*n+k]+2);
                }
            }
        }
        return res;
    }
