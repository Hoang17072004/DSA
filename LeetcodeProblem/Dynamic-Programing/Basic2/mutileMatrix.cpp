#include<iostream>
using namespace std;
const int N=310;
int d[N],L[N][N],n;
int main() {
	cin>>n;
	for (int i=0;i<=n;i++) cin>>d[i];
	for (int dis=1;dis<n;dis++) {
		for (int i=1;i+dis<=n;i++) {
			int j=i+dis;
			L[i][j]=L[i+1][j]+d[i-1]*d[i]*d[j];
			for (int k=i;k<j;k++) L[i][j]=min(L[i][j],L[i][k]+L[k+1][j]+d[i-1]*d[k]*d[j]);
		}
	}
	cout<<L[1][n];
}