#include<bits/stdc++.h>
using namespace std;
const int maxN=110;
int n;
string s[maxN];
int visit[maxN];
vector<int> g[maxN];
stack<int> topo;
void printImpossible() {
	cout<<"Impossible";
	exit(0);
}
void dfs(int u) {
	visit[u]=1;
	for (auto v: g[u]) {
		if (visit[v]==1) printImpossible();
		if (!visit[v]) dfs(v);
	}
	topo.push(u);
	visit[u]=2;
}
void solve(string x,string y) {
	for (int i=0;i<min(x.size(),y.size());i++) {
		if (x[i]!=y[i]) {
			g[x[i]-'a'].push_back(y[i]-'a');
			return;
		}
		if (x.size()>y.size()) printImpossible();
	}
}
int main() {
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>s[i];
		if (i) solve(s[i-1],s[i]);
	}
	for (int i=0;i<26;i++) {
		if (!visit[i]) dfs(i);
	}
	while(!topo.empty()) {
		cout<<char(topo.top()+'a');
		topo.pop();
	}
}
