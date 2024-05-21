int leastInterval(vector<char>& tasks, int n) {
        int count[26]={0};
        for (int i=0;i<tasks.size();i++) count[tasks[i]-'A']++;
        priority_queue<int> pq;
        for (int i=0;i<26;i++) {
            if (count[i]) pq.push(count[i]);
        }
        int time=0;
        while(!pq.empty()) {
            vector<int> remain;
            int cycle=n+1;
            while(cycle&&!pq.empty()) {
                time++;
                int max_pre=pq.top();
                pq.pop();
                max_pre--;
                if (max_pre>0) remain.push_back(max_pre);
                cycle--;
            }
            for (int count: remain) {
                pq.push(count);
            }
            if (pq.empty()) break;
            time+=cycle;
        }
        return time;

    }
