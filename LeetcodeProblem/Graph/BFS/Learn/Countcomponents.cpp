#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+7;
int n,m,components=0;
bool visit[maxN];
vector<int> g[maxN];
void bfs(int s) {
	components++;
	queue<int> q;
	q.push(s);
	visit[s]=true;
	while(q.size()) {
		int u=q.front();
		q.pop();
		for (auto v: g[u]) {
			if (!visit[v]) {
				q.push(v);
				visit[v]=true;
			}
		}
	}
}
int main() {
	cin>>n>>m;
	while(m--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	fill_n(visit,n+1,false);
	for (int i=1;i<=n;i++) if (!visit[i]) bfs(i);
	cout<<components;
}
