#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		long long ans=0,sum=0;
		long long a[2*n+1];
		for (int i=1;i<=2*n;i++) {
			cin>>a[i];
			ans+=abs(a[i]);
			sum+=abs(a[i]-(-1));
		}
		if (n==1) ans=min(ans,abs(a[1]-a[2]));
		if (n==2) ans=min(ans,abs(a[1]-2)+abs(a[2]-2)+abs(a[3]-2)+abs(a[4]-2));
		if (n%2==0) {
			for (int i=1;i<=2*n;i++) {
				ans=min(ans,sum-abs(a[i]-(-1))+abs(a[i]-n));
			}
		}
		cout<<ans<<endl;
	}
}