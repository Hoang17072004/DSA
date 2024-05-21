#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v,c;
	Edge(int u,int v,int c):u(u),v(v),c(c){
	}
};
struct DsU{
	vector<int> par;
	void init(int n) {
		par.resize(n+5,0);
		for (int i=1;i<=n;i++) par[i]=i;
	}
	int find(int u) {
		return par[u]==u?u: par[u]=find(par[u]);
	}
	bool join(int u,int v) {
		u=find(u);
		v=find(v);
		if (u==v) continue;
		par[v]=u;
		return true;
	}
} dsu;
int n,m,totalWeight=0;
vector<Edge> edges;
int main() {
	cin>>n>>m;
	for (int i=1;i<m;i++) {
		int u,v,c;
		cin>>u>>v>>c;
		edges.push_back({u,v,c});
	}
	dsu.init(n);
	sort(edges.begin(),edges.end(),[](Edge&x,Edge &y){
		return x.c<y.c;
	});
	for (auto &e: edges) {
		if (dsu.join(e.u,e.v)) continue;
		totalWeight+=e.c;
	}
	cout<<totalWeight<<'\n';
}
