double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> v;
        int n=quality.size();
        for (int i=0;i<n;i++) {
            //workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
            v.push_back({(double)(wage[i])/quality[i],(double)quality[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<double> pq;
        double res=1000000000000; 
        double s=0;
        for (int i=0;i<n;i++) {
            s+=v[i][1];
            pq.push(v[i][1]);
            if (pq.size()>k) {
                s-=pq.top();
                pq.pop();
            }
            if (pq.size()==k) res=min(res,s*v[i][0]);
        }
        return res;
    }
