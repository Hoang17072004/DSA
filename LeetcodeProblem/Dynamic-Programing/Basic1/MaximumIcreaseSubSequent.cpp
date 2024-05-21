#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int f[N],a[N],n;
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) f[i]=1;
	for (int i=2;i<=n;i++) {
		for (int j=1;j<i;j++) {
			if (a[j]<=a[i]) f[i]=max(f[i],f[j]+1);
		}
	}
	int mx=f[1];
	for (int i=2;i<=n;i++) mx=max(mx,f[i]);
	cout<<mx;
}