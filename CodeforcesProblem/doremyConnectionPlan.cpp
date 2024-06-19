#include<bits/stdc++.h>
using namespace std;
bool solve() {
	long long n,c; cin>>n>>c;
	vector<pair<long long,int>> a(n+1);
	for (int i=1;i<=n;i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	long long s=a[1].first;
	sort(a.begin()+1,a.end(),[&](pair<long long,int>&b,pair<long long,int>&d){
		return b.first-b.second*c>d.first-d.second*c;	
	});
	for (int i=1;i<=n;i++) {
		if (a[i].second==1) continue;
		if (s+a[i].first-c*a[i].second<0) return false;
		s+=a[i].first;
	}
	return true;
}
int main() {
	int t; cin>>t;
	while(t--) if (solve()) cout<<"YES\n"; else cout<<"NO\n"; 
	
}