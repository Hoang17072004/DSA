class Solution {
public: 
    bool visit[1000000]={};
    int dfs(int u,vector<vector<int>>&al) {
        visit[u]=1;
        int res=0;
        for (int v: al[u]) res=max(res,dfs(v,al));
        return res+1;
    }
    int maximumInvitations(vector<int>& fav) {
        int res=0;
        vector<vector<int>> al(fav.size());
        for (int i=0;i<fav.size();i++) {
            if (fav[fav[i]]!=i) al[fav[i]].push_back(i); 
        }
        for (int i=0;i<fav.size();i++) {
            if (fav[fav[i]]==i) res+=dfs(i,al);
        }
        for (int i=0;i<fav.size();i++) {
            int cnt=0,j=i;
            for(;visit[j]==false;j=fav[j]) {
                visit[j]=true;
                ++cnt;
            }
            for (int k=i;k!=j;k=fav[k]) --cnt;
            res=max(res,cnt);
        }
        return res;
    }
};
