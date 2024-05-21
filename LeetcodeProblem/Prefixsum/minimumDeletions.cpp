int minimumDeletions(string s) {
        vector<int> a(s.size(),0);
        vector<int> b(s.size(),0);
        int cnt=0;
        for (int i=0;i<s.size();i++) {
            a[i]=cnt;
            if (s[i]=='b' ) cnt++;
        }
        cnt=0;
        for (int i=s.size()-1;i>=0;i--) {
            b[i]=cnt;
            if (s[i]=='a') cnt++;
        }
        int res=INT_MAX;
        for (int i=0;i<s.size();i++) res=min(res,a[i]+b[i]);
        return res;
    }
