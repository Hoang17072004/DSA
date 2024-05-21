#include<iostream>
using namespace std;
const int N=310;
int n,a[N];
bool L[N][N];
int main() {
	cin>>n;
	int t=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		t+=a[i];
	}
	for (int i=0;i<=n;i++) L[i][0]=true;
	for (int i=1;i<=n;i++) {
		for (int j=1;2*j<=t;j++) {
			L[i][j]|=L[i-1][j];
			if (a[i]<=j) L[i][j]|=L[i-1][j-a[i]];
		}
	}
	int mx=0;
	for (int i=1;2*i<=t;i++) {
		if (L[n][i]) mx=i;
	}
	cout<<mx<<" "<<t-mx<<endl;
}