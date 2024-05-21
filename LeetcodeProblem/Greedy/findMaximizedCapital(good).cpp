class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> a;
        int n=profits.size();
        for (int i=0;i<n;i++) a.push_back({capital[i],profits[i]});
        sort(a.begin(),a.end());
        priority_queue<int> pq;
        int cnt=0;
        int res=0;
        for (int i=0;i<n;i++) {
            while(pq.size()&&w<a[i][0]) {
                w+=pq.top();
                pq.pop();
                res+=a[i][1];
                cnt++;
                if (cnt==k) return w;
            }
            if (w>=a[i][0]) {
                pq.push(a[i][1]);
            } else break;
            
        }
        while(pq.size()&&cnt<k) {
            w+=pq.top();
            cnt++;
            pq.pop();
        }
        return w;
    }
};
