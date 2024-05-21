int longestValidSubstring(string word, vector<string>& forbidden) {
        int len=0;
        unordered_map<string,int> count;
        for(int i=0;i<forbidden.size();i++) {
            int size=forbidden[i].size();
            len=max(len,size);
            count[forbidden[i]]++;
        }
        int res=0;
        int n=word.size();
        int right=n;
        for (int i=n-1;i>=0;i--) {
            string temp="";
            for (int j=i;j<right&&j-i<len;j++) {
                temp+=word[j];
                if (count[temp]) {
                    right=j;
                    break;
                }
            }
            res=max(res,right-i);
        }
        return res;
    }
