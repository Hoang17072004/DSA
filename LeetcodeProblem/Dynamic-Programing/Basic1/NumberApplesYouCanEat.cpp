#include<iostream>
using namespace std;
const int N=1e3+10;
int m,n,a[N][N];
long long f[N][N];
int main() {
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++) cin>>a[i][j];
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			f[i][j]=max(f[i-1][j],f[i][j-1])+a[i][j];
		}
	}
	cout<<f[m][n];
}