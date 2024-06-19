#include<bits/stdc++.h>
using namespace std;
vector<int> parent,sz;
void make_set(int n) {
	parent.resize(n);
	sz.resize(n);
	for (int i=0;i<n;i++) parent[i]=i,sz[i]=0;	
}
int find_set(int v) {
	return v==parent[v]?v: parent[v]=find_set(parent[v]);
}
vector<int> ans,path;
bool dfs(int u,int p,vector<vector<int>> &g,int f) {
	path.push_back(u);
	if (u==f) {
		ans=path;
		return true;
	}
	for (int v: g[u]) {
		if (v==p) continue;
		if (dfs(v,u,g,f)) return true;
	}
	path.pop_back();
	return false;
}
bool union_set(int a,int b) {
	a=find_set(a);
	b=find_set(b);
	if (a==b) return false;
	if (sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	parent[b]=a;
	return true;
}
void solve() {
	int n,m; 
	cin>>n>>m;
	int u,v,w;
	vector<pair<int,pair<int,int>>> edges;
	for (int i=0;i<m;i++) {
		cin>>u>>v>>w;
		edges.push_back({w,{u-1,v-1}});
	}
	sort(edges.rbegin(),edges.rend());
	pair<int,int> find;
	int best=INT_MAX;
	vector<vector<int>> g(n);
	make_set(n);
	for (auto &e: edges) {
		int u=e.second.first,v=e.second.second;
		if (union_set(u,v)) {
			g[u].push_back(v);
			g[v].push_back(u);
		} else {
			best=e.first;
			find.first=u,find.second=v;
		}
	}
	path.resize(0);
	dfs(find.first,find.first,g,find.second);
	cout<<best<<" "<<ans.size()<<endl;
	for (int x: ans) cout<<x+1<<" ";
	cout<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}