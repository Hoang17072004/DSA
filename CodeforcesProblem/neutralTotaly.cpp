#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,m; cin>>n>>m;
	vector<int> a(n),b(m);
	vector<int> num;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<m;i++) cin>>b[i];
	sort(b.rbegin(),b.rend());
	vector<int> c(m+n);
	merge(a.begin(),a.end(), b.begin(),b.end(), c.begin(), greater<int>());
	for (int x: c) cout<<x<<" ";
	cout<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}