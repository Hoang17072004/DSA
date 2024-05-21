#include<iostream>
using namespace std;
const int N=1e3+10;
int a[N],P[N],Q[N],n,U,L;
int main() {
	cin>>n>>U>>L;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		P[i]=1;Q[i]=1;
		for (int j=1;j<=i-L;j++) {
			if (a[i]-U<=a[j]&&a[j]<a[i]) Q[i]=max(Q[i],P[j]+1);
			if (a[j]>a[i]&&a[j]<=a[i]+U) P[i]=max(P[i],Q[j]+1);
		}
	}
	int mx=Q[1];
	for (int i=1;i<=n;i++) mx=max(mx,max(P[i],Q[i]));
	cout<<mx;
}