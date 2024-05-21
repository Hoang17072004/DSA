#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=1e5+5;
const int INF =1e9;
int n,m;
vector<pair<int,int>> g[N];
int dis[N];
int prim(int s) {
	int res=0;
	priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> q;
	dis[s]=0;
	q.push({s,0});
	while(q.size) {
		auto top=q.top(); q.pop();
		int curDis=top.fi;int u=top.se;
		if (curDis!=dis[u]) continue;
		res+=dis[u]; dis[u]=-INF;
		for (auto &e: g[u]) {
			int v=e.fi;int c=e.se;
			if (dis[v]>c) {
				dis[v]=c;
				q.push({dis[v],v});
			}
		}
	}
	return ret;
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int u,v,c;
		cin>>u>>v>>c;
		g[u].push_back({v,c});
		g[v].push_back({u,c});
	}
	cout<<prim(1)<<'\n';
}
