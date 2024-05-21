int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int l=0,r=min(tasks.size(),workers.size());
        while(l<r){
            int need=0;
            int m=l+(r-l+1)/2;
            multiset<int> s(workers.end()-m,workers.end());
            for (int i=m-1;i>=0;i--) {
                auto it=prev(s.end());
                if (*it<tasks[i]) {
                    it=s.lower_bound(tasks[i]-strength);
                    if (it==s.end()||++need>pills) break;
                }
                s.erase(it);
            }
            if (s.empty()) l=m; else r=m-1;
        }
        return l;
    }
