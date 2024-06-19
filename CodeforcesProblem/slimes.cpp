#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		vector<int>a(n);
		for (int &x: a) cin>>x;
		vector<int> ans(n,n);
		for (int z=0;z<2;z++) {
			vector<long long> s(n+1);
			for (int i=0;i<n;i++) s[i+1]=s[i]+a[i];
			vector<int> p(n,-1);
			for (int i=1;i<n;i++) {
				int j=(z?n-i-1:i);
				int l=1,r=i;
				while(l<=r) {
					int m=(l+r)/2;
					if (s[i]-s[i-m]>a[i]&&p[i-1]>=i-m) {
						ans[j]=min(ans[j],m);
						r=m-1;
					} else l=m+1;
				}
				if (a[i-1]>a[i]) ans[j]=1;
				p[i]=(a[i]==a[i-1]?p[i-1]:i-1);
			}
			reverse(a.begin(),a.end());
		}
		for (int i=0;i<n;i++) cout<<(ans[i]==n?-1:ans[i])<<" ";
		cout<<"\n";
	}
}