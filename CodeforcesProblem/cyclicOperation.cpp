#include<bits/stdc++.h>
using namespace std;
bool solve() {
	int n,k; cin>>n>>k;
	int b[n+1];
	vector<int> arrown(n+1,0);
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		arrown[b[i]]++;
	}
	queue<int> q;
	for (int i=1;i<=n;i++) {
		if (!arrown[i]) q.push(i);
	}
	vector<bool> visit(n+1,0);
	if (k==1) for (int i=1;i<=n;i++) if (b[i]!=i) return false;
	while(q.size()) {
		int u=q.front();
		visit[u]=1;
		q.pop();
		arrown[b[u]]--;
		if (!arrown[b[u]]) q.push(b[u]);
	}
	for (int u=1;u<=n;u++) {
		if (!visit[u]) {
			int cnt=1;
			int v=b[u];
			visit[u]=1;
			while(v!=u) {
				cnt++;
				visit[v]=1;
				v=b[v];
			}
			if (cnt!=k) return false;
			
		}
	}
	return true;
}
int main() {
	int t; cin>>t;
	while(t--) if(solve()) cout<<"YES\n"; else cout<<"NO\n"; 
}