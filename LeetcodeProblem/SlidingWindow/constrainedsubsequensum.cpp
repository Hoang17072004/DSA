#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k; cin>>n>>k;
	int a[n+1]={0};
	for (int i=1;i<=n;i++) cin>>a[i];
	deque<int> dq;
	int ans=0;
	dq.push_back(0);
	int dp[n+2]={0};
	for (int i=1;i<=n+1;i++) {
		while(!dq.empty()&&dq.front()<i-k) dq.pop_front();
		dp[i]=dp[dq.front()]+a[i];
		ans+=a[i];
		while(!dq.empty()&&a[dq.back()]>=dp[i]) dq.pop_back();
		dq.push_back(i);
	}
	for (int i=1;i<=n+1;i++) cout<<dp[i]<<" "; cout<<endl;
	cout<<ans-dp[n];
}
