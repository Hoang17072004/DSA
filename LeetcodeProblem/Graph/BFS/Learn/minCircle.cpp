#include<bits/stdc++.h>
using namespace std;
const int maxN=210;
int n;
int visit[maxN],d[maxN];
vector<int> g[maxN];
int bfs(int s) {
	fill_n(d,n+1,0);
	fill_n(visit,n+1,false);
	queue<int> q;
	q.push(s);
	visit[s]=true
	while(q.size()) {
		int u=q.front();
		q.pop();
		for (auto v: g[u]) {
			if (v==s) return d[u]+1;
			if (!visit[v]) {
				visit[v]=1;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return 0;
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			int h; cin>>h;
			if (h) g[i].push_back(j);
		}
	for (int i=1;i<=n;i++) {
		int ans=bfs(i);
		if (ans) cout<<ans<<endl;
		else cout<<"NO WAY\n";
	}
}
