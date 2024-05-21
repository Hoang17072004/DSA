#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
int a[N];
struct DSU{
	vector<map<int,int>> color;
	vector<int> parent,sz;
	DSU(int n):color(n),parent(n),sz(n){
		
	}
	void make_set(int v) {
		parent[v]=v;
		sz[v]=1;
		color[v][a[v]]=1;
	}
	int find_set(int v) {
		if (v==parent[v]) return v;
		int p=find_set(parent[v]);
		parent[v]=p;
		return p;
	}
	void union_sets(int a,int b) {
		a=find_set(a);
		b=find_set(b);
		if (a!=b) {
			if (sz[a]<sz[b]) swap(a,b);
			parent[b]=a;
			sz[a]+=sz[b];
			for (auto p: color[b]) m[p.first]+=p.second;
			color[b].clear();
		}
	}
	int query(int v,int c) {
		v=find_set(v);
		return color[v].find(c)!=color[v].end()?color[v][c]:0;
	}
};
int main() {
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	DSU g(n+5);
	for (int i=1;i<=n;i++) g.make_set(i);
	while(q--) {
		int op,x,y;
		cin>>op>>x>>y;
		if (op==1) g.union_sets(x,y);
		else cout<<g.query(x,y)<<endl;
	}
}
