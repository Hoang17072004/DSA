long long minimumSteps(string s) {
        long long res=0;
        int cnt=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='1') cnt++;
            else res+=cnt;
        }
        return res;
    }
