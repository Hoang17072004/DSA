class Solution {
public:
    int mod=1e9+7;
    int modPow(int x,unsigned int y, unsigned int m) {
        if (y==0) return 1;
        long p=modPow(x,y/2,m)%m;
        p=(p*p)%m;
        return y%2?(p*x)%m: p;
    }
    int dfs(vector<vector<int>> &al,int cur,long long &prod) {
        int total_cnt=1;
        for (auto next: al[cur]) {
            total_cnt+=dfs(al,next,prod);
        }
        prod=prod*total_cnt%mod;
        return cur!=0?total_cnt: prod;
    }
    int waysToBuildRooms(vector<int>& pr) {
        vector<vector<int>> al(pr.size());
        long long fact=1,prod=1;
        for (int i=1;i<pr.size();i++){
            al[pr[i]].push_back(i);
            fact=fact*(i+1)%mod;
        }
        return fact*modPow(dfs(al,0,prod),mod-2,mod)%mod;
    }
};
