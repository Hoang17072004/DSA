#include<bits/stdc++.h>
const long long INF = 2000000000000000000LL;
struct Edge{
	int v;
	long long w;
};
struct Node{
	int u;
	long long Dist_u;
};
struct cmp{
	bool operator() (Node a,Node b) {
		return a.Dist_u>b.Dist_u;
	}
};
void dijkstraSparse(int n,int s,vector<vector<Edge>> &E,vector<long long>&D,vector<int>&trace) {
	D.resize(n,INF);
	trace.resize(n,-1);
	vetor<bool> P(n,0);
	D[s]=0;
	priority_queue<Node,vector<Node>,cmp> h;
	h.push({s,D[s]});
	while(h.size()) {
		Node x=h.top();
		h.pop();
		int u=x.u;
		if (P[u]==true) continue;
		P[u]=true;
		for (auto e: E[u]) {
			int v=e.v;
			long long w=e.w;
			if (D[v]>D[u]+w) {
				D[v]=D[u]+w;
				h.push({v,D[v]});
				trace[v]=u;
			}
		}
	}
}
vector<int> trace_path(vector<int> &trace,int S,int u) {
	if (u!=S&&trace[u]==-1) return vector<int>(0);
	vector<int> path;
	while(u!=-1) {
		path.push_back(u);
		u=trace[u];
	}
	reverse(path.begin(),path.end());
	return path;
}
