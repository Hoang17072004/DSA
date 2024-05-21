int numRectangle(vector<int> heights) {
        stack<int> st;
        
        int res=0;
        vector<int> sum(heights.size(),0);
        for (int i=0;i<heights.size();i++) {
            while(st.size()&&heights[st.top()]>=heights[i]) st.pop();
            if (st.empty()) sum[i]=heights[i]*(i+1);
            else {
                sum[i]=sum[st.top()];
                sum[i]+=heights[i]*(i-st.top());
            }
            st.push(i);
           
        }
        for (int x: sum) res+=x;
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        vector<int> heights(mat[0].size(),0);
        int res=0;
        for (int i=0;i<mat.size();i++) {
            for (int j=0;j<mat[i].size();j++) {
                heights[j]=mat[i][j]==0?0:heights[j]+1;
            }
            res+=numRectangle(heights);
        }
        return res;
    }