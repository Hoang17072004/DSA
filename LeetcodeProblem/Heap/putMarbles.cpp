long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        int n=weights.size();
        priority_queue<int> maxheap;
        if (k==1) return 0;
        for (int i=0;i<n-1;i++) {
            if (minheap.size()<k-1) {
                minheap.push(weights[i]+weights[i+1]);
            } else {
                if (minheap.top()<weights[i]+weights[i+1] ) {
                    minheap.pop();
                    minheap.push(weights[i]+weights[i+1]);
                }
            }
            if (maxheap.size()<k-1) {
                maxheap.push(weights[i]+weights[i+1]);
            } else {
                if (maxheap.top()>weights[i]+weights[i+1]) {
                    maxheap.pop();
                    maxheap.push(weights[i]+weights[i+1]);
                }
            }
        }
        long long res=0;
        while(minheap.size()&&maxheap.size()) {
            res+=minheap.top()-maxheap.top();
            minheap.pop();
            maxheap.pop();
        }
        return res;
    }
