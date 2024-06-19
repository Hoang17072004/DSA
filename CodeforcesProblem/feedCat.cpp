#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
void solve() {
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> a(m);
	vector<int>op(n+1);
	vector<vector<int>> del(n+1);
	for (auto &e: a) {
		cin>>e.x>>e.y;
		op[e.x]++;
		del[e.y].emplace_back(e.x);
	}
	multiset<int> cur;
	vector<int> dp(n+1,0);
	for (int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		for (int j=0;j<op[i];j++) cur.insert(i);
		if (cur.size())dp[i]=max(dp[i],dp[*cur.begin()-1]+(int)cur.size());
		for (int e: del[i]) cur.erase(cur.find(e));
	}
	cout<<dp[n]<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}