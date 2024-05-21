vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> a(queries.size(),vector<int>(2));
        for (int i=0;i<queries.size();i++) {
            a[i][0]=queries[i];
            a[i][1]=i;
        }
        sort(a.begin(),a.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minheap;
        int j=0;
        vector<int> v(queries.size());
        for (int i=0;i<queries.size();i++) {
            while(j<intervals.size()&&intervals[j][0]<=a[i][0]) {
                minheap.push({intervals[j][1]-intervals[j][0]+1,j});
                j++;
            }
            while(minheap.size()&&intervals[minheap.top().second][1]<a[i][0]) minheap.pop();
            if (minheap.size())
             v[a[i][1]]=minheap.top().first; else v[a[i][1]]=-1;
        }
        return v;
    }
