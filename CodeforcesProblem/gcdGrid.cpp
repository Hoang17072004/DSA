#include<bits/stdc++.h>

using namespace std;
int main() {
	int t; cin>>t;
	int m,n;
	int a[101][101];
	
	int moveX[]={0,1};
	int moveY[]={1,0};
	
	while(t--) {
		cin>>m>>n;
		
		for (int i=0;i<m;i++) {
			for (int j=0;j<n;j++) cin>>a[i][j];
		}
		int g=__gcd(a[0][0],a[m-1][n-1]);
		
		int res=1;
		int dp[m+1][n+1]={0};
		for (int i=1;i*i<=g;i++) {
			if (g%i==0) {
				int can[]={i,g/i};
				for (int x: can) {
					
					memset(dp,0,sizeof(dp));
					dp[0][0]=1;
					for (int j=0;j<m;j++) {
						for (int k=0;k<n;k++) {
							if (j==0&&k==0) continue;
							if (a[j][k]%x) continue;
							if (j&&dp[j-1][k]) dp[j][k]=1;
							if (k&&dp[j][k-1]) dp[j][k]=1;
						}
					}
					if (dp[m-1][n-1]) {
						res=max(res,x);
					}
				}
			}
		}
		cout<<res<<endl;
	}
	
}