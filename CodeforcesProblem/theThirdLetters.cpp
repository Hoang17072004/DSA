#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int,int>>> &g,int u,vector<bool>&visit,vector<long long>&d) {
	visit[u]=1;

	for (auto &e: g[u]) {
		int v=e.first,w=e.second;
		if (visit[v]) continue;
		d[v]=d[u]+w;
		dfs(g,v,visit,d);
	} 
}
bool solve() {
	int n,m; cin>>n>>m;
	vector<vector<pair<int,int>>> g(n);
	vector<vector<int>> e;
	while(m--) {
		int a,b,d; cin>>a>>b>>d;
		a--,b--;
		
		e.push_back({a,b,d});
		g[a].push_back({b,d});
		g[b].push_back({a,-d});
	}
	vector<bool> visit(n,0);
	vector<long long> d(n,0);
//	return true;
	for (int u=0;u<n;u++) {
		if (!visit[u]) {
			d[u]=0;
			dfs(g,u,visit,d);
		}
	}
	for (auto &x: e) {
		if (d[x[1]]-d[x[0]]!=x[2]) return false;
	}
	return true;
}
int main() {
	int t; cin>>t;
	while(t--) if(solve()) cout<<"YES\n"; else cout<<"NO\n"; 
}