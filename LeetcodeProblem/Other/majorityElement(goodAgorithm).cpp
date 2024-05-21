class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> candidates(2,{0,0});
        for (int num: nums) {
            bool found=false;
            for (int i=0;i<2;i++) {
                if (candidates[i].first==num) {
                    candidates[i].second++;
                    found=true;
                    break;
                }
                
            }
            if (!found) {
                for (int i=0;i<2;i++) {
                    if (candidates[i].second==0) {
                        candidates[i]={num,1};
                        found=true;
                        break;
                    }
                }
            }
            if (!found) {
                for (int i=0;i<2;i++) candidates[i].second--;
            }
        }
        vector<int> ans;
        for (int i=0;i<2;i++) {
            
            int cnt=0;
            for (int num:nums) cnt+=num==candidates[i].first;
            if (cnt>n/3) ans.push_back(candidates[i].first);

        }
        if (ans.size()>1&&ans[1]==ans[0]) ans.pop_back();
        return ans;
    }
};
