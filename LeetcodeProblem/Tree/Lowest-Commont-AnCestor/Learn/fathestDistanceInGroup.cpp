#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
const int N=2e5+8;
int n,k,root;
vector<int> g[N],group[N>>1];
int h[N],up[N][18];
void dfs(int u) {
	for (int v: g[u]) {
		h[v]=h[u]+1;
		for (int j=1;j<18;j++) up[v][j]=up[up[v][j-1]][j-1];
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
int dist(int u,int v) {
	int p=lca(u,v);
	return h[u]+h[v]-2*h[p];
}
int diameter(vector<int> &meeting) {
	int A=meeting[0],max_dist=0,B=A,d;
	for (int x: meeting) {
		d=dist(A,x);
		if (max_dist<d) {
			max_dist=d;
			B=x;
		}
	}
	max_dist=0;
	for (int x: meeting) {
		d=dist(B,x);
		max_dist=max(maxdist,d);
	}
	return max_dist;
}
int main() {
	cin>>n>>k;
	for (int i=1,x;i<=n;i++) {
		cin>>x>>up[i][0];
		group[x].push_back(i);
		g[up[i][0]].push_back(i);
		if (up[i][0]==0) root=i;
	}
	dfs(root);
	for (int i=1;i<=k;i++) cout<<diameter(group[i])<<'\n';
}
