#include<bits/stdc++.h>
using namespace std;
bool path(vector<vector<int>>&g,int u,int p,int t,vector<int>&temp){
	temp.push_back(u);
	if (u==t) return true;
	for (int v: g[u]) {
		if (v==p) continue;
		if (path(g,v,u,t,temp)) return true;
	}
	temp.pop_back();
	return false;
}
int maxdist(vector<vector<int>>&g,int u,int p) {
	int s=0;
	for (int v: g[u]) {
		if (v==p) continue;
		s=max(s,maxdist(g,v,u));
	}
	return s+1;
}
void solve() {
	int n; cin>>n;
	int a,b; cin>>a>>b; a--;b--;
	vector<vector<int>> g(n);
	for (int i=1;i<n;i++) {
		int u,v; cin>>u>>v;
		u--,v--; g[u].push_back(v); g[v].push_back(u);
	}
	vector<int> temp;
	path(g,a,a,b,temp);
	int mid=(temp.size()-1)/2;
//	for (int x: temp) cout<<x<<" "; cout<<endl;
	int st=temp[mid];
	int d=maxdist(g,st,st)-1;
//	cout<<"st="<<st+1<<",d="<<d<<endl;
	cout<<2*(n-1)-d+temp.size()-1-mid<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}