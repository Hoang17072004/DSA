#include<bits/stdc++.h>
using namespace std;
const int maxN=110;
int n,m;
int visit[maxN],ans[maxN];
vector<int> g[maxN];
stack<int> topo;
void dfs(int u) {
	visit[u]=1;
	for (auto v: g[u]) {
		if (visit[v]==1) {
			cout<<"Error: graph contains a cycle";
			exit(0);
		}
		if (!visit[v]) dfs(v);
	}
	topo.push(u);
	visit[u]=2;
}
int main() {
	cin>>n>>m;
	while(m--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	for (int i=1;i<=n;i++) {
		if (!visit[i]) dfs(i);
	}
	int cnt=0;
	while(!topo.size()) {
		ans[topo.top()]=++cnt;
		topo.pop();
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
