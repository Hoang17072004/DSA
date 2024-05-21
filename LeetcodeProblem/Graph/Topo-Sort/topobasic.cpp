#include<bits/stdc++.h>
using namespace std;
const int maxN=110;
int n,m;
int indegree[maxN],ans[maxN];
vector<int> g[maxN],topo;
queue<int> listSource;
int main() {
	cin>>n>>m;
	while(m--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		indegree[v]++;
	}
	for (int u=1;u<=n;u++) {
		if (!indegree[u]) listSource.push(u);
	}
	while(!listSource.empty()) {
		int u=listSource.front();
		listSource.pop();
		topo.push_back(u);
		for (auto v: g[u]) {
			indegree[v]--;
			if (!indegree[v]) listSource.push(v);
		}
	}
	if (topo.size()<n) {
		cout<<"Error: graph contains a cycle";
		return 0;
	}
	int cnt=0;
	for (auto x: topo) ans[x]=++cnt;
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
