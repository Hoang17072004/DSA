int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp=[&](vector<int> &a,vector<int> &b) {
            return a[1]<b[1];
        };
        sort(points.begin(),points.end(),cmp);
        int pre_end=points[0][1];
        int ans=1;
        for (int i=1;i<points.size();i++) {
            if (points[i][0]>pre_end) {
                ans++;
                pre_end=points[i][1];
            }
        }
        return ans;
    }
