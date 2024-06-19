#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin>>n;
	int cnt[n+1]={0};
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		if (x<n) cnt[x]++;
	}
	int m=0;
	while(cnt[m]) m++;
	vector<long long> dp(m+1,INT_MAX);
	dp[m]=0;
	for (long long i=m;i>=1;i--) for (int j=0;j<i;j++) dp[j]=min(dp[j],dp[i]+i*cnt[j]);
	cout<<dp[0]-m<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}