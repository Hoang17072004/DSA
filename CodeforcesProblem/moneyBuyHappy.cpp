#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=5e4+5;
ll t,m,x,c[55],h[55],dp[maxn];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>x;ll sum=0,ans=0;
		for(int i=1;i<=maxn;++i) dp[i]=1e18;
		for(int i=1;i<=m;++i) cin>>c[i]>>h[i],sum+=h[i];
		for(ll i=1;i<=m;++i)
		{
			for(ll j=sum;j>=h[i];--j)
			{
				if((i-1)*x>=dp[j-h[i]]+c[i])
				{
					dp[j]=min(dp[j],dp[j-h[i]]+c[i]);
					ans=max(ans,j);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}