#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+7;
int n,m,s,t;
int par[maxN];
bool visit[maxN];
vector<int> g[maxN];
void bfs(int s) {
	fill_n(par,n+1,-1);
	fill_n(visit,n+1,false);
	queue<int> q;
	q.push(s);
	visit[s]=true;
	while(q.size()) {
		int u=q.front();
		q.pop();
		for (auto v: g[u]) {
			if (!visit[v]) {
				visit[v]=false;
				par[v]=u;
				q.push(v);
			}
		}
	}
}
int main() {
	cin>>n>>m>>s>>t;
	while(m--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	bfs(s);
	vector<int> path;
	for (int v=t;v!=-1;v=par[v]) path.push_back(v);
	reverse(path.begin(),path.end());
	for (auto v: path) cout<<v<<" ";
}
