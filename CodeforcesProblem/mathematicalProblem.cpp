#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,k,d; cin>>n>>k>>d;
	int a[n+5],v[k+5];
	int res=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		res+=a[i]==i;
	}
	res=res+(d-1)/2;
	for (int i=1;i<=k;i++) cin>>v[i];
	for (int i=1;i<=min(2*n,d-1);i++) {
		int cnt=0;
		for (int j=1;j<=n;j++) {
			int val=(i<=k)?v[i]:(i%k==0)?v[k]:v[i%k];
			if (j<=val) a[j]++;
			cnt+=a[j]==j;
		}
		res=max(res,cnt+(d-1-i)/2);
	}
	cout<<res<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}