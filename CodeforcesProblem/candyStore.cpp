#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b) {
	if (b==0) return a;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b) {
	return a*b/gcd(a,b);
}
int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<long long> a(n),b(n);
		for (int i=0;i<n;i++) cin>>a[i]>>b[i];
		long long g=0,l=1,ans=1;
		for (int i=0;i<n;i++) {
			g=gcd(g,a[i]*b[i]);
			l=lcm(l,b[i]);
			if (g%l) {
				ans++;
				g=a[i]*b[i];
				l=b[i];
			}
		}
		cout<<ans<<endl;
	}
}