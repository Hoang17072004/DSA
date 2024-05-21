int minFlips(string s) {
        string s1,s2;
        int n=s.size();
          s+=s;
        for (int i=0;i<s.size();i++) {
            s1+=i%2?'0':'1';
            s2+=i%2?'1':'0';
        }
      
   
        int res=INT_MAX;
        int cnt1=0,cnt2=0;
        for (int i=0;i<s.size();i++) {
            if (s1[i]!=s[i]) cnt1++;
            if (s2[i]!=s[i]) cnt2++;
            if (i>=n) {
                if (s1[i-n]!=s[i-n]) cnt1--;
                if (s2[i-n]!=s[i-n]) cnt2--;
            }
            if (i>=n-1) res=min(res,min(cnt1,cnt2));
        }
        return res;
    }
