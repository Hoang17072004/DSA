#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin>>n;
	unsigned long long a[n];
	for (int i=0;i<n;i++) cin>>a[i];
	unsigned long long res=0;
	int x=0;
	for (int i=1;i<n;i++) {
//		if (a[i]<a[i-1]) {
			double val=a[i-1]/(double)a[i];
			x=max(0.0,x+ceil(log2(val)));
			
			res+=x;
		//	cout<<"i="<<i<<",t="<<t<<",cur="<<cur<<endl;
//			unsigned long long one=1;
//			a[i]*=(one<<t);
//		} 
		//cur=a[i];
	}
	cout<<res<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}