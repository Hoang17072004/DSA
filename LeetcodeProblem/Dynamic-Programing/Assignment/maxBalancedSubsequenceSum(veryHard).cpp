class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<int,long long> m{{INT_MIN,0}};
        for (int i=0;i<nums.size();i++) {
            auto it=m.upper_bound(nums[i]-i);
            long long sum=nums[i]+max(0LL,prev(it)->second);
            m.insert_or_assign(it,nums[i]-i,sum);
            for (;it!=end(m)&&it->second<=sum;) m.erase(it++);
        }
        return rbegin(m)->second;
    }
};
