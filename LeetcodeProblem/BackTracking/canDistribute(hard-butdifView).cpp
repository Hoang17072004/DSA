bool Try(vector<int> &count,vector<int> &quantity,int k) {
       if (k==quantity.size()) return true;
       for (int i=0;i<count.size();i++) {
           if (count[i]>=quantity[k]) {
               count[i]-=quantity[k];
               if(Try(count,quantity,k+1)) return true;
               count[i]+=quantity[k];
           }
       }
       return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) m[nums[i]]++;
        vector<int> count;
        for (auto x: m) count.push_back(x.second);
        sort(quantity.rbegin(),quantity.rend());
        return Try(count,quantity,0);
    } 
