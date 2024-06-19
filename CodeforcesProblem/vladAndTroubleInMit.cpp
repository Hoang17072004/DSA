#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
int n;
const int N=1e5+69;
int dp[N][3];
string s;
vector<int> adj[N];
void dfs(int u) {
	//dp[u][0]= nothing open
	//dp[u][1]= P open
	//dp[u][2]= S open
	dp[u][0]=INT_MAX;
	if (s[u]!='S') dp[u][1]=0;
	else dp[u][1]=INF;
	if (s[u]!='P') dp[u][2]=0;
	dp[u][2]=INF;  
	int tot=0;
	for (int v: adj[u]) {
		dfs(v);
		dp[u][1]=dp[u][1]+min({dp[v][1],dp[v][2]+1,dp[v][0]});
		dp[u][2]=dp[u][2]+min({dp[v][2],dp[v][1]+1,dp[v][0]});
		tot+=dp[v][0];
	}
	if (s[u]!='C') tot=INF;
	dp[u][0]=min({tot,dp[u][1]+1,dp[u][2]+1});
}
void solve() {
	cin>>n;
	for (int i=1;i<=n;i++) adj[i].clear();
	for (int i=2;i<=n;i++) {
		int x; cin>>x;
		adj[x].push_back(i);
	}
	cin>>s; s="0"+s;
	dfs(1);
	cout<<min({dp[1][0],dp[1][1],dp[1][2]})<<"\n";
}
int main() {
	int t=1;
	cin>>t;
	for (int i=1;i<=t;i++) solve();
	return 0;
}