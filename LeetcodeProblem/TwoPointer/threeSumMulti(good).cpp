int threeSumMulti(vector<int>& arr, int target) {
        map<int,int> m;
        int cnt=0;
        int mod=1e9+7;
        for (int i=0;i<arr.size();i++) {
            cnt+=m[target-arr[i]];
            cnt%=mod;
            for (int j=0;j<i;j++) m[arr[i]+arr[j]]++;
        }
        return cnt;
    }
