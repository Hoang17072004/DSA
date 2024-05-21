class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res=0;
        for (int num: nums) {
            if (s.find(num-1)==s.end()) {
                int cur=num;
                int cnt=0;
                while(s.find(cur)!=s.end()) {
                    s.erase(cur);
                    cur++;
                    cnt++;
                }
                res=max(res,cnt);
            }
        }
        return res;
    }
};
