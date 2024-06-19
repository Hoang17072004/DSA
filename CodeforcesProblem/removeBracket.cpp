#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,s; cin>>n>>s;
	long long x[n+1],y[n+1];
	for (int i=1;i<=n;i++) {
		int j; cin>>j;
		if (i==1||i==n) x[i]=y[i]=j;
		else if (j<=s) x[i]=0,y[i]=j;
		else x[i]=s,y[i]=j-s;
	}
	long long dp[n+1][2];
	dp[1][0]=dp[1][1]=0;
	for (int i=2;i<=n;i++) {
		dp[i][0]=min(dp[i-1][0]+y[i-1]*x[i],dp[i-1][1]+x[i-1]*x[i]);
		dp[i][1]=min(dp[i-1][0]+y[i-1]*y[i],dp[i-1][1]+x[i-1]*y[i]);
	}
	cout<<dp[n][0]<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}