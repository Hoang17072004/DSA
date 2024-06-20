#include<bits/stdc++.h>
using namespace std;
void solve() {
	long long n; cin>>n;
	vector<int> res;
	if (n&1) {
		for (int i=n-n/2;i<=n+n/2;i++) {
			res.push_back(i+2);
		}
		res[0]--,res[n-1]++,res[n-2]++;
		
	} else {
		for (int i=n/2;i<=3*n/2;i++) if (i!=n) res.push_back(i);
	}
	for (int x: res) cout<<x<<" "; cout<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}