int sumSubarrayMins(vector<int>& arr) {
        vector<int> a(arr.size(),-1);
        vector<int> b(arr.size(),arr.size());
        stack<int> st1;
        stack<int> st2;
        for (int i=0;i<arr.size();i++) {
            while(st1.size()&&arr[st1.top()]>arr[i]) st1.pop();
            if (st1.size()) a[i]=st1.top();
            st1.push(i);
            while(st2.size()&&arr[i]<arr[st2.top()]) {
                b[st2.top()]=i;
                 st2.pop();
            }
            st2.push(i);

        }
        
        long long s=0;
        int mod=1e9+7;
        for (int i=0;i<arr.size();i++) {
           
            s+=(long long)arr[i]*(i-a[i])*(b[i]-i);
            s%=mod;
            }
        return s;
        
    }
