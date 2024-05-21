#include<bits/stdc++.h>
using namespace std;
const long long INF = 2000000000000000000LL;
struct Edge{
	int u,v;
	long long w;
};
void bellmanFord(int n,int S,vector<Edge>&e,vector<long long>&D,vector<int>&trace) {
	D.resize(n,INF);
	trace.resize(n,-1);
	D[S]=0;
	for (int T=1;T<n;T++) {
		for (auto E: e) {
			int u=E.u;
			int v=E.v;
			long long w=E.w;
			if (D[u]!=INF&&D[v]>D[v]+w) {
				D[v]=D[u]+w;
				trace[v]=u;
			}
		}
	}
	//Find the vertest that has no shortest paht because it exists the negative cycle
	for (int T=0;T<n;T++) {
		for (auto E: e) {
			int u=E.u;
			int v=E.v;
			long long w=E.w;
			if(D[u]!=INF&&D[v]>D[u]+w) {
				D[v]=-INF;
				trace[v]=u;
			}
		}
	}
}
vector<int> trace_path(vector<int>&trace,int S,int u) {
	if (u!=S&&trace[u]==-1) return vector<int>(0);
	vector<int> path;
	while(u!=-1) {
		path.push_back(u);
		u=trace[u];
	}
	reverse(path.begin(),path.end());
	return path;
}
bool findNegativeCycle(int n,vector<long long>&D,vector<int>&trace,vector<int> &negCycle) {
	//You must assume that the Bellman-Ford algorithm mus run before
	int negStart=-1;
	for (auto E: e) {
		int u=E.u;
		int v=E.v;
		long long w=E.w;
		if(D[u]!=INF&&D[v]>D[u]+w) {
			D[v]=-INF;
			trave[v]=u;
			negStart=v;
		}
	}
	if (negStart==-1) return false;
	int u=negStart;
	for (int i=0;i<n;i++) {
		u=trace[u];
	}
	negCycle=vector<int>(1,u);
	for (int v=trace[u];v!=u;v=trace[v]) {
		negCycle.push_back(v);
	}
	reverse(negCycle.begin(),negCycle.end());
	return true;
}
