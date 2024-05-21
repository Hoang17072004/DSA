class Solution {
public:
    int countTriplets(vector<int>& nums) {
        map<int,int> m;
        for (int i=0;i<nums.size();i++) {
            for (int j=0;j<nums.size();j++) m[nums[i]&nums[j]]++;
        }
        int s=0;
        for (int i=0;i<nums.size();i++) {
            for (auto x: m) {
                if ((x.first&nums[i])==0) s+=x.second;
            }
        }
        return s;
    }
};
