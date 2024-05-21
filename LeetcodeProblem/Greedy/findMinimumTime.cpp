static bool comp(vector<int> &a,vector<int> &b) {
         return a[1]<b[1];
    }
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),comp);
        
        bool visited[2010]={0};
     
        int cnt=0;
        for (int i=0;i<tasks.size();i++) {
            int num=0;
            for (int j=tasks[i][0];j<=tasks[i][1];j++) if(visited[j]) num++;
            int j=tasks[i][1];
            while(num<tasks[i][2]) {
                if (!visited[j]) {
                    num++;
                    cnt++;
                    visited[j]=1;
                }
                j--;
            }
        }
        return cnt;
    }
