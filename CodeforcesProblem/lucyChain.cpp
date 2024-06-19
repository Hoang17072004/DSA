#include<bits/stdc++.h>
using namespace std;
const int INF=int(1e9);
const int N=int(1e7)+5;
int mind[N];
void precalc() {
	for (int i=0;i<N;i++) mind[i]=i;
	for (int p=2;p<N;p++) {
		if (mind[p]!=p) continue;
		for (int d=2*p;d*d<N;d+=p) mind[d]=min(mind[d],p);
	}
}
int x,y;
vector<int> getPrimes(int v) {
	vector<int> ps;
	while(v>1) {
		if (ps.empty()||ps.back()!=mind[v]) ps.push_back(mind[v]);
		v/=mind[v];
	}
	return ps;
}
void solve() {
	int d=y-x;
	if (d==1) {
		cout<<-1<<endl;
		return;
	}
	int r=INF;
	for (int p:getPrimes(d)) r=min(r,((x+p-1)/p)*p);
	cout<<r-x<<endl;
}
int main() {
	precalc();
	int t; cin>>t;
	while(t--) {
		cin>>x>>y;
		solve();
	}
}