int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<string,int>>> bucket(26);
        int cnt=0;
        for (int i=0;i<words.size();i++) bucket[words[i][0]-'a'].push_back({words[i],0});
        for (char c: s) {
            auto temp=bucket[c-'a'];
            bucket[c-'a'].clear();
            for (auto& x: temp) {
                x.second++;
                if (x.second==x.first.size()) cnt++;
                else bucket[x.first[x.second]-'a'].push_back(x);
            }
        }
        return cnt;
    }
