#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+7;
int n,m;
int visit[maxN],dp[maxN];
vector<int> g[maxN],revTopo;
void dfs(int u){
	visit[u]=1;
	for (auto v: g[u]) {
		if (!visit[v]) dfs(v);
	}
	revTopo.push_back(u);
	visit[u]=2;
}
int main() {
	cin>>n>>m;
	while(m--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	for (int i=1;i<=n;i++) if (!visit[i]) dfs(i);
	int ans=0;
	for (auto u: revTopo) {
		for (auto v: g[u]) {
			dp[u]=max(dp[u],dp[v]+1);
		}
		ans=max(ans,dp[u]);
	}
	cout<<ans;
}
