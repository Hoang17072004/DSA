class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visit(n,0);
        int res=0;
        for (int i=0;i<n;i++) {
            if (!visit[i]) {
                int start=nums[i];
                int cnt=0;
                do{
                    start=nums[start];
                    cnt++;
                    visit[start]=1;
                } while(start!=nums[i]);
                res=max(res,cnt);
            }
        }
        return res;
    }
};
