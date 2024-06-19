#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	int n,k,x,y;
	while(t--) {
		cin>>n>>k;
		vector<bool> mark(n+1,0);
		
		for (int i=0;i<k;i++) {
			cin>>x>>y;
			mark[x]=mark[y]=1;
		}
		int cnt=0;
		for (int i=1;i<=n;i++) cnt+=!mark[i];
		vector<long long> dp(max(cnt+1,3),0);
		dp[0]=dp[1]=1;
		int mod=1e9+7;
		
		for (int i=2;i<=cnt;i++) {
			dp[i]=(dp[i-1]+(2*(i-1)*dp[i-2])%mod)%mod;
		}
		cout<<dp[cnt]<<endl;
	}
}