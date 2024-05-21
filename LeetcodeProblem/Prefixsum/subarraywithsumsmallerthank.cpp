int subarraywithsumsmallerthank(vector<int> &nums,int k) {
        vector<int> prefix(nums.size()+1,0);
        set<int> s;
        for (int i=1;i<=nums.size();i++) {
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int res=INT_MIN;
       
        for (int i=0;i<=nums.size();i++) {
            auto it=s.lower_bound(prefix[i]-k);
            if (it!=s.end()) res=max(res,prefix[i]-*it);
            s.insert(prefix[i]);
        }
        
        return res;

    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> nums(0,n);
        int res=INT_MIN;
        for (int top=0;top<m;top++){
            nums.assign(n,0);
            for (int bottom=top;bottom<m;bottom++) {
                for (int i=0;i<n;i++) nums[i]+=matrix[bottom][i];
                
                res=max(res,subarraywithsumsmallerthank(nums,k));
                
            }
            
        }
        return res;
    }
