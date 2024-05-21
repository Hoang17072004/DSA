class Solution {
public:
    bool able(string &a,string &b) {
        int n=a.size();
        int cnt=0;
        for (int i=0;i<n;i++) {
            if (a[i]!=b[i]) cnt++;
        }
        return cnt==1;
    }
    void bfs(vector<vector<int>> &g,vector<int> parent[],int n,int start,int end) {
        vector<int> d(n,1005);
        queue<int> q;
        parent[start]={-1};
        q.push(start);
        d[start]=0;
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            for (int u: g[x]) {
                if (d[u]>d[x]+1) {
                    d[u]=d[x]+1;
                    q.push(u);
                    parent[u].clear();
                    parent[u].push_back(x);
                } else if (d[u]==d[x]+1) parent[u].push_back(x);
            }
        }
    }
    void shortestPaths(vector<vector<int>> &Paths,vector<int> &path,vector<int> parent[],int node) {
        if (node==-1) {
            Paths.push_back(path);
            return;
        }
        for (int u: parent[node]) {
            path.push_back(u);
            shortestPaths(Paths,path,parent,u);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size(),start=-1,end=-1;
        vector<vector<string>> ans;
        for (int i=0;i<n;i++) {
            if (wordList[i]==beginWord) start=i;
            if (wordList[i]==endWord) end=i;
        }
        if (end==-1) return ans;
        if (start==-1) {
            wordList.emplace(wordList.begin(),beginWord);
            start=0;
            end++;
            n++;
        }
        vector<vector<int>> g(n,vector<int>()),Paths;
        vector<int> parent[n],path;
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (able(wordList[i],wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        bfs(g,parent,n,start,end);
        shortestPaths(Paths,path,parent,end);
        vector<string> now;
        for (auto &u: Paths) {
            now.clear();
           for (int i=0;i<u.size()-1;i++) now.push_back(wordList[u[i]]);
           reverse(now.begin(),now.end());
           now.push_back(endWord);
           ans.push_back(now);
        }
        return ans;
    }
};
