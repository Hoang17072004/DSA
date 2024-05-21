class Solution {
public:
    int bfs(vector<vector<int>>&couch,vector<bool> &visit,int s) {
        visit[s]=1;
        int res=0;
        queue<int> q;
        q.push(s);
        while(q.size()) {
            int u=q.front();
            q.pop();
            for (int v: couch[u]) {
                if (!visit[v]) {
                    res++;
                    visit[v]=1;
                    q.push(v);
                }
            } 
        }
        return res;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        vector<int> idx(n);
        for (int i=0;i<n;i++) {
            idx[row[i]]=i;
        }
        vector<vector<int>> couch(n/2);
        for (int i=0;i<n;i++) {
            int partner=row[i]%2==0?row[i]+1:row[i]-1;
            couch[idx[row[i]]/2].push_back(idx[partner]/2);;
        }
        int ans=0;
        vector<bool> visit(n/2,0);
        for(int i=0;i<n/2;i++) {
            if (!visit[i]) {
                ans+=bfs(couch,visit,i);
            }
        }
        return ans;
    }
};
