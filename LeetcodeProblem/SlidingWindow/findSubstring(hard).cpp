vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> dict;
        for (int i=0;i<words.size();i++) dict[words[i]]++;
        vector<int> res;
        int n=s.length(),m=words[0].length(),w=words.size();
        for (int k=0;k<m;k++) {
            int left=k;
            map<string,int> count;
            int cnt=0;
            for (int i=k;i<n;i+=m)  {
                string temp=s.substr(i,m);
                if (dict[temp]==0) {
                    cnt=0;
                    left=i+m;
                    count.clear();
                } else {
                    count[temp]++;
                    cnt++;
                    while(count[temp]>dict[temp]) {
                        string pre=s.substr(left,m);
                        count[pre]--;
                        cnt--;
                        left+=m;
                    }
                    if (cnt==w) {
                        res.push_back(left);
                        count[s.substr(left,m)]--;
                        left+=m;
                        cnt--;
                    }
                }   
            }
        }
        return res;
    }
