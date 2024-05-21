int findTheLongestSubstring(string s) {
        unordered_map<int,int> m;
        int cur=0;
        m[0]=-1;
        int ans=0;
        for (int i=0;i<s.size();i++) {
            auto n=string("aeiou").find(s[i]);
            if (n!=string::npos) cur^=(1<<n);
            if (!m.count(cur)) m[cur]=i;
            ans=max(ans,i-m[cur]);
        }
        return ans;
    }
