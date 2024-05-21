vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int,int> m;
        for (int i=0;i<intervals.size();i++) {
            m[intervals[i][0]]++;
            m[intervals[i][1]]--;
        }
       
        m[newInterval[0]]++;
        m[newInterval[1]]--;
        
        int cnt=0;
        int start=0;
        vector<vector<int>> res;
        for (auto x: m) {
            if (cnt==0) {
                start=x.first;
            }
            cnt+=x.second;
            if (cnt==0) {
                res.push_back({start,x.first});
            }
        }
        return res;
    }
