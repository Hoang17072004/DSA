long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<int> pq;
        for (int i=0;i<nums1.size();i++) if (nums1[i]-nums2[i]) pq.push(abs(nums1[i]-nums2[i]));
        
        int k=k1+k2;
        int pre=0;
        if (pq.size()) pre=pq.top();
        int cnt=1;
        if (k&&pq.size()) pq.pop(); 
               pq.push(0);
        while(k>0&&pq.size()) {
            int cur=pq.top();
            long x=(pre-cur)*cnt;
            if (x<=k) {
                k-=x;
                cnt++;
                pre=cur;
                pq.pop();
                if (k==0) {
                    for (int i=0;i<cnt;i++) pq.push(cur);
                } 

            } else {
                int a=k/cnt;
                int b=k%cnt;
                int c=pre-a;
                for (int i=0;i<cnt-b;i++) pq.push(c);
                for (int i=0;i<b;i++) pq.push(c-1);
                //pq.push(cur);
                k=0;
            }
        }
            long s=0;
            while(pq.size()) {
                s+=(long)pq.top()*pq.top();
                pq.pop();
            }
            return s;
    }
