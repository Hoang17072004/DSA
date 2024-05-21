int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int,int>> a;
        for (int i=0;i<arr.size();i++) a.push_back({arr[i],i});
        sort(a.begin(),a.end());
        int s1=0,s2=0;
        int cnt=0;
        for (int i=0;i<arr.size();i++) {
            s1+=i;
            s2+=a[i].second;
            if (s1==s2) {
                cnt++;
                s1=s2=0;
            }
        }
        return cnt;
    }
