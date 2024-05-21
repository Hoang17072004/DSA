#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=1e5+9;
int n;
vector<int> g[N];
int h[N],up[N][17];
void dfs(int u) {
	for (int v: g[u]) {
		if (v==up[u][0]) continue;
		h[v]=h[u]+1;
		g[v][0]=u;
		for (int j=0;j<17;j++) up[u][j]=up[up[u][j-1]][j-1];
		dfs(v);
	}
}
int lca(int u,int v) {
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int j=0;(1<<j)<=k;j++) {
			if (k>>j&1) u=up[u][j];
		}
	}
	if (u==v) return u;
	int k=__lg(h[u]);
	for (int j=k;j>=0;j--) {
		if (up[u][j]!=up[v][j]) {
			u=up[u][j];
			v=up[v][j];
		}
	}
	return up[u][0];
}
int main() {
	while(cin>>n,n) {
		for (int i=1;i<=n;i+) g[i].clear();
		for (int i=1,u,v;i<n;i++) {
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		char c;
		int m,root(1),u,v;
		cin>>m;
		while(m--) {
			cin>>c;
			if (c=='!') cin>>root;
			else {
				cin>>u>>v;
				int uv=lca(u,v);
				int ur=lca(u,root);
				int vr=lca(v,root);
				cout<<(uv^ur^vr)<<'\n';
			}
		}
	}
	
}
