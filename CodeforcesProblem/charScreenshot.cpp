#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
int timer=0;
void dfs(int v,vector<vector<int>>&g,vector<bool>&vis,vector<int>&tout) {
	vis[v]=true;
	for (int u: g[v]) {
		if (!vis[u])dfs(u,g,vis,tout);
	}
	tout[v]=timer++;
}
void solve() {
	timer=0;
	int n,k;
	cin>>n>>k;
	vector<vector<int>> a(k,vector<int>(n));
	vector<int> authors(k);
	for (int i=0;i<k;i++) {
		for (int j=0;j<n;j++) {
			cin>>a[i][j];
			a[i][j]--;
		}
		authors[i]=a[i][0];
	}
	vector<vector<int>> g(n);
	for (int i=0;i<k;i++) {
		for (int j=1;j+1<n;j++) {
			int i1=a[i][j],i2=a[i][j+1];
			g[i1].push_back(i2);
		}
	}
	vector<int> tout(n,-1);
	vector<bool> vis(n);
	for (int i=0;i<n;i++) {
		if (tout[i]==-1) {
			dfs(i,g,vis,tout);
		}
	}
	for (int i=0;i<k;i++) {
		for (int j=1;j+1<n;j++) {
			int i1=a[i][j],i2=a[i][j+1];
			if (tout[i1]<tout[i2]) {
				cout<<"NO";
				return;
			}
		}
	}
	cout<<"YES";
}
int main() {
	int t; cin>>t;
	while(t--) {
		solve();
		cout<<"\n";
	}
}