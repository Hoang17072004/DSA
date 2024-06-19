#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin>>n;
	long long s=0,mx=0,delta=0,ans=0;
	for (int i=0;i<n;i++) {
		long long x; cin>>x;
		s+=x;
		mx=max(mx,s);
		if (s-mx<delta) {
			ans=mx;
			delta=s-mx;
		}
	}
	cout<<ans<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}