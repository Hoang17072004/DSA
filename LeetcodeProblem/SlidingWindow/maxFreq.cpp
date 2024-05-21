int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.size(),res=0;
        int m[26]={0};
        map<string,int> ma;
        for (int k=minSize;k<=maxSize;k++) {
        int cnt=0;
        memset(m,0,sizeof(m));
        for (int i=0;i<n;i++) {
            
            m[s[i]-'a']++;
            if (m[s[i]-'a']==1) cnt++;
            if(i>=k) {
                m[s[i-k]-'a']--;
                if(m[s[i-k]-'a']==0) cnt--;
               
            }
            if (i>=k-1) {
                
                string temp=s.substr(i-k+1,k);
            
            
                if (cnt<=maxLetters) res=max(res,++ma[temp]);
            }
           
            
            
        }
        }
        return res;
    }
