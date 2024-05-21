int totalSteps(vector<int>& nums) {
        vector<int> maxEat(nums.size());
        stack<int> st;
        int steps=0;
        for (int i=nums.size()-1;i>=0;i--){
            while(st.size()&&nums[i]>nums[st.top()]) {
                maxEat[i]=max(maxEat[i]+1,maxEat[st.top()]);
                st.pop();
            }
            st.push(i);
            steps=max(steps,maxEat[i]);
        }
        return steps;
    }
