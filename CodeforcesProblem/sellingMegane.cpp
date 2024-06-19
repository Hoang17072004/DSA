#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin>>n;
	int a[n];
	vector<int>sons(n,0);
	vector<int> ans;
	for (int i=0;i<n;i++ ) cin>>a[i],a[i]--,sons[a[i]]++;
	int c[n];
	for (int i=0;i<n;i++) cin>>c[i];
	queue<int> q;
	for (int i=0;i<n;i++) if (sons[i]==0) q.push(i);
	bool added[n]={0};
	while(q.size()) {
		int u=q.front();
		q.pop();
		added[u]=true;
		ans.push_back(u);
		sons[a[u]]--;
		if (sons[a[u]]==0) q.push(a[u]);
	}
	for (int u=0;u<n;u++) {
		if (!added[u]) {
			vector<int> cycle={u};
			int v=a[u];
			while(v!=u) {
				cycle.push_back(v);
				v=a[v];
			}
			int sm=INT_MAX;
			for (int x: cycle) sm=min(sm,c[x]),added[x]=1;
			for (int i=0;i<cycle.size();i++) {
				if (c[cycle[i]]==sm) {
					ans.insert(ans.end(),cycle.begin()+i+1,cycle.end());
					ans.insert(ans.end(),cycle.begin(),cycle.begin()+i+1);
					break;
				}
			}
		}
	}
	for (int x: ans) cout<<x+1<<" ";
	cout<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}