#include<bits/stdc++.h>
using namespace std;
int MOD=998244353;
long long add(long long x,long long y) {
	return ((x+y)%MOD+MOD)%MOD;
}
long long mul(long long x,long long y) {
	return x*y%MOD;
}
long long bipow(long long x,long long y) {
	long long z=1;
	while(y) {
		if (y&1) z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
long long inv(long long x) {
	return bipow(x,MOD-2);
}
long long divide(long long x,long long y) {
	return mul(x,inv(y));
}
void solve() {
	int n;cin>>n;
	int w[n];
	for (int i=0;i<n;i++) cin>>w[i];
	
	long long res=1;
	for (int i=1;i<=n/6;i++) res=mul(res,divide(i+n/6,i));
	for (int i=0;i<=n-3;i+=3) {
		sort(w+i,w+i+3,greater<int>());
		int cnt=1;
		if (w[i+1]+w[i+2]==w[i]+w[i+1]) cnt++;
		if (w[i]+w[i+2]==w[i]+w[i+1]) cnt++;
		res=mul(res,cnt);
	}
	cout<<res<<endl;
}
int main() {
//	long long 
//	int t; cin>>t;
//	while(t--) 
	solve();
}