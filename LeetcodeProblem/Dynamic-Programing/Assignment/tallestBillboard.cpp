class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int> dp;
        dp[0]=0;
        for (int r: rods) {
            unordered_map<int,int> newdp=dp;
            for (auto p: dp) {
                int diff=p.first;
                int taller=p.second;
                int shorter=taller-diff;
                int newtaller=newdp[diff+r];
                newdp[diff+r]=max(newtaller,taller+r);
                int newdiff=abs(shorter+r-taller);
                int newtaller2=max(shorter+r,taller);
                newdp[newdiff]=max(newtaller2,newdp[newdiff]);
            }
            dp=newdp;
        }
        return dp[0];
    }
};
