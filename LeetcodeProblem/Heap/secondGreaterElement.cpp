vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
       vector<int> a(n,-1);
       
       vector<vector<int>> m(n,vector<int>(0));
      stack<int> s;
       for (int i=0;i<n;i++) {
          
      
           while(s.size()&&nums[s.top()]<nums[i]) {
               m[i].push_back(s.top());
               s.pop();
           }
           s.push(i);
         
       }
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> st;

       for (int i=0;i<n;i++) {
           while (st.size()&&nums[i]>st.top().first) {
               a[st.top().second]=nums[i];
               st.pop();
           }
           for (int x: m[i]) st.push({nums[x],x});
       }

      
       
       return a;
        
    }
