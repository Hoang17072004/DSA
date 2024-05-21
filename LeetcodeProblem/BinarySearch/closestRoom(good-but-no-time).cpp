static bool comp(vector<int> &a,vector<int> &b) {
        return a[1]>b[1];
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(),rooms.end(),comp);
        for (int i=0;i<queries.size();i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),comp);
        int j=0;
        set<int> s;
        
        vector<int> res(queries.size());
        for (int i=0;i<queries.size();i++) {
            while(j<rooms.size()&&rooms[j][1]>=queries[i][1]) {
                s.insert(rooms[j][0]);
                j++;
            }
            auto it=s.lower_bound(queries[i][0]);
            int second=(it==s.end())?-1: *it;
            int first=(it==s.begin())?-1: *prev(it);
            res[queries[i][2]]=(min(first,second)==-1)?max(first,second):abs(first-queries[i][0])<=(second-queries[i][0])?first: second;
            
        }
        return res;
    }
