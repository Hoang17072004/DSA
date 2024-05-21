int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for (int i=0;i<nums.size();i++) {
            if (st.empty()||nums[st.top()]>nums[i]) st.push(i);
        }
        int ans=0;
        for (int i=nums.size()-1;i>=0;i--) {
            while(st.size()&&nums[i]>=nums[st.top()]) {
                ans=max(ans,i-st.top());
                st.pop();
            }
        }
        return ans;
    }
