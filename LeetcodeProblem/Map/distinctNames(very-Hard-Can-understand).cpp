long long distinctNames(vector<string>& ideas) {
        unordered_map<string,int> m;
        for (int i=0;i<ideas.size();i++) m[ideas[i]]++;
        vector<vector<int>> accept(26,vector<int>(26,0));
        int n=ideas.size();
        for (int i=0;i<n;i++) {
            string str=ideas[i];
            for (int c='a';c<='z';c++) {
                str[0]=c;
                if (m.find(str)==m.end()) {
                    accept[ideas[i][0]-'a'][c-'a']++;
                }
            }
        }
        long long res=0;
        for (int i=0;i<n;i++) {
            string str=ideas[i];
            for (int c='a';c<='z';c++) {
                str[0]=c;
                if (m.find(str)==m.end()) {
                    res+=accept[c-'a'][ideas[i][0]-'a'];
                }
            }
        }
        return res;
    }
