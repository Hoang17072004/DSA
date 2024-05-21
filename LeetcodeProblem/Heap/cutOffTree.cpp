#include<bits/stdc++.h>
using namespace std;
int cutOffTree(vector<vector<int>>& forest) {
        int m=forest.size(),n=forest[0].size();
        bool checked[51][51];
        for (int i=0;i<=50;i++) {
            for (int j=0;j<=50;j++) checked[i][j]=0;
        }
        int cnt=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (forest[i][j]==0)  {
                    cnt++;
                    checked[i][j]=1;
                }
            }
        }
       
        int length=m*n-cnt;
        int size=length;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int prex=0,prey=0;
        if (checked[0][0]==0)pq.push({forest[0][0],{0,0}});
        int walk=-1;
        while(length) {
            if (pq.empty()) return -1;
            pair<int,int> p=pq.top().second;
            int i=p.first,j=p.second;
            
            
            if (abs(i-prex)+abs(j-prey)>1) return -1;
            cout<<"i="<<i<<"\tj="<<j<<"\tvalue="<<pq.top().first<<"\tpq.size()="<<pq.size()<<endl;
            pq.pop();
            checked[i][j]=1;
            prex=i;prey=j;
            walk++;
            length--;
            if (i>0&&checked[i-1][j]==0) pq.push({forest[i-1][j],{i-1,j}});
            if (j>0&&checked[i][j-1]==0) pq.push({forest[i][j-1],{i,j-1}});
            if (i<m-1&&checked[i+1][j]==0) pq.push({forest[i+1][j],{i+1,j}});
            if (j<n-1&&checked[i][j+1]==0) pq.push({forest[i][j+1],{i,j+1}});

        }
        return walk;
    }
int main()  {
	vector<vector<int>> forest={{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};
	cout<<cutOffTree(forest);
}