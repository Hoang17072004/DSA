#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; long long c;
	cin>>n>>c;
	vector<int> a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	long long res=(c+1)*(c+2)/2;
	unordered_set<int> s(a.begin(),a.end());
	long long cnt[2]={0};
	for (int x: s) {
		res-=x/2+1+c-x+1;
		cnt[x&1]++;
	}
	
	res+=cnt[0]+cnt[1]+max(cnt[0]*(cnt[0]-1)/2,0ll)+max(cnt[1]*(cnt[1]-1)/2,0ll);cout<<res<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) {
		solve();
	}
}