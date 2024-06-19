#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n; long long l; cin>>n>>l;
	vector<vector<int>> a(n,vector<int>(2,0));
	for (int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	sort(a.begin(),a.end(),[](vector<int>&a,vector<int>&b){
		return a[1]<b[1];	
	});
	int res=0;
	for (int i=0;i<n;i++) { 
		multiset<int> s;
		long long sum=0;
		for (int j=i;j<n;j++) {
			int dis=a[j][1]-a[i][1];
			sum+=a[j][0];
			s.insert(a[j][0]);
			while(sum+dis>l&&s.size()) {
				sum-=*s.rbegin();
				s.erase(prev(s.end()));
			}
			res=max(res,(int)s.size());
		}
		
	}
	cout<<res<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) {
		solve();
	}
}