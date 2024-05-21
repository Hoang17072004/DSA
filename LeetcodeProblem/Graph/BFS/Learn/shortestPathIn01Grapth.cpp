#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int maxN=1e5+7;
int n,m;
int d[maxN];
vector<pair<int,int>> g[maxN];
void bfs(int s) {
	fill_n(d,n+1,inf);
	deque<int> q;
	q.push_back(s);
	d[s]=0;
	while(q.size()) {
		int u=q.front();
		q.pop_front();
		if (u==n) return;
		for (auto edge: g[u]) {
			int v=edge.second;
			int w=edge.first;
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				if (w) q.push_back(v);
				else q.push_front(v);
			}
		}
	}
	d[n]=-1;
}
int main() {
	cin>>n>>m;
	while(m--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back({0,v});
		g[v].push_back({1,u});
	}
	bfs(1);
	cout<<d[n];
}
