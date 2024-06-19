#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,m; cin>>n>>m;
	int l,r;
	map<int,int> first,second;
	for (int i=0;i<n;i++) {
		cin>>l>>r;
		l--,r--;
		if (l) first[l]++,first[r+1]--;
		if (r<m-1) second[l]++,second[r+1]--;
	}
	int s1=0,s2=0;
	int res=0;
	for (auto &p: first) {
		s1+=p.second;
		res=max(res,s1);
	}
	for (auto &p: second) {
		s2+=p.second;
		res=max(res,s2);
	}
	cout<<res<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}