bool find132pattern(vector<int>& nums) {
        vector<int> smaller(nums.size());
        smaller[0]=nums[0];
        for (int i=1;i<nums.size();i++) {
            smaller[i]=min(nums[i],smaller[i-1]);

        }
        stack<int> st;
        for (int i=nums.size()-1;i>=0;i--) {
            while(st.size()&&st.top()<=smaller[i]) st.pop();
            if (st.size()&&st.top()<nums[i]) return true;
            st.push(nums[i]);
        }
        return false;
    }
