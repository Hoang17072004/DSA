class Solution {
public:
    int dp[1001][26][26];
    int Try(vector<string>&words,int i,int first,int last) {
        if (i==words.size()) return 0;
        if (dp[i][first-'a'][last-'a']!=-1) return dp[i][first-'a'][last-'a'];
        int s=words[i].size()-(last==words[i][0])+Try(words,i+1,first,words[i].back());
        s=min(s,(int)words[i].size()-(words[i].back()==first)+Try(words,i+1,words[i][0],last));
        return dp[i][first-'a'][last-'a']=s;
    }
    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        return Try(words,1,words[0][0],words[0].back())+words[0].size();
    }
};
