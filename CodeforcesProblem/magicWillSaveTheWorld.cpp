#include<bits/stdc++.h>
using namespace std;
void solve() {
	int w,f; cin>>w>>f;
	int n;cin>>n;
	int s[n];
	int sums=0;
	for (int i=0;i<n;i++) cin>>s[i],sums+=s[i];
	vector<int> dp(sums+1,0);
	dp[0]=1;
	for (int i=0;i<n;i++) {
		for (int j=sums;j>=s[i];j--) dp[j]=dp[j]||dp[j-s[i]];
	}
	int res=INT_MAX;
	for (int i=0;i<=sums;i++) {
		if (dp[i])res=min(res,max((i+w-1)/w,(sums-i+f-1)/f));
	}
	cout<<res<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}