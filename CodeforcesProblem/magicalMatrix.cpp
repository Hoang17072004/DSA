#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	int n;
	while(t--) {
		cin>>n;
		vector<vector<int>> matrix(n+1,vector<int>(n+1));
		for (int i=n;i>0;i--) {
			for (int j=1;j<=n;j++) matrix[i][j]=j;
			for (int j=1;j<=n;j++) matrix[j][i]=j;
		}
		long long s=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) s+=matrix[i][j];
		}
		cout<<s<<" "<<2*n<<endl;
		for (int i=n;i>0;i--) {
			cout<<"1 "<<i<<" ";
			for (int j=1;j<=n;j++) cout<<j<<" ";
			cout<<"\n2 "<<i<<" ";
			for (int j=1;j<=n;j++) cout<<j<<" ";
			cout<<endl;
		}
	}
}