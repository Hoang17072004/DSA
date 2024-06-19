#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin>>n;
	int a[n];
	for (int i=0;i<n;i++) cin>>a[i];
	vector<int> pos,neg;
	int prefix=0;
	vector<int> res;
	if (*max_element(a,a+n)==0) {
		cout<<"No\n"; return;
	} else cout<<"Yes\n";
	for (int i=0;i<n;i++) if (a[i]>=0) pos.push_back(a[i]);
	else neg.push_back(a[i]);
	for (int i=0;i<n;i++) {
		if (prefix<=0) {
			res.push_back(pos.back()); pos.pop_back();
		} else {
			res.push_back(neg.back()); neg.pop_back();
		}
		prefix+=res.back();
	}
	for (int x: res) cout<<x<<" ";
	cout<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}