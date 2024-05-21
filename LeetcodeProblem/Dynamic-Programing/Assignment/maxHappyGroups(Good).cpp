class Solution {
public:
    map<vector<int>,int> dp;
    int dfs(vector<int>&cnt,int left) {
        auto it=dp.find(cnt);
        if (it!=dp.end()) return it->second;
        int res=0,bz=cnt.size();
        for (int j=1;j<bz;j++) {
            if (--cnt[j]>=0) res=max(res,(left==0)+dfs(cnt,(bz+left-j)%bz));
            ++cnt[j];
        }
        return dp[cnt]=res;
    }
    int maxHappyGroups(int bz, vector<int>& groups) {
        vector<int> cnt(bz);
        int res=0;
        for (int group: groups) {
            if (group%bz==0) ++res;
            else if (cnt[bz-group%bz]) {
                ++res;
                --cnt[bz-group%bz];
            }
            else ++cnt[group%bz];
        }
        return dfs(cnt,0)+res;
    }
};
