class Solution {
public:
    int traverse(vector<int> &nums,vector<vector<int>> &next,int cur,vector<int> &temp,int target){
        temp[cur]=nums[cur];
        for (int n: next[cur]) {
            if (temp[n]) continue;
            temp[cur]+=traverse(nums,next,n,temp,target);
            if (temp[cur]>target) return 1e7;
        }
        if (temp[cur]==target) return 0;
        return temp[cur];
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0,n=nums.size();
        for (int i=0;i<n;i++) sum+=nums[i];
        vector<vector<int>> next(n);
        for (auto &e: edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        for (int i=n;i>1;i--) {
            if (sum%i) continue;
            vector<int> temp(n);
            if (traverse(nums,next,0,temp,sum/i)==0) return i-1;
        }
        return 0;
    }
};
