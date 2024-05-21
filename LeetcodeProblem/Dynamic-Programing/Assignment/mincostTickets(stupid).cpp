class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        unordered_set<int> s(days.begin(),days.end());
        vector<int> dp(367,0);
        for (int i=1;i<=365;i++) {
            dp[i]=dp[i-1];
            if (s.find(i)!=s.end()) {
                dp[i]=min({dp[i-1]+cost[0],dp[max(0,i-7)]+cost[1],dp[max(0,i-30)]+cost[2]});
            }
        }
        return dp[365];
    }
};
