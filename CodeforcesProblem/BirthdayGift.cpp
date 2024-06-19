#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define all(a) a.begin(), a.end()
void solve() {
	int n,x;
	cin>>n>>x;
	x++;
	vector<int> a(n);
	for (int &i: a) cin>>i;
	int res=-1;
	for (int i=30;i>=0;i--) {
		bool open=false;
		vector<int> b;
		
		for (int j=0;j<a.size();j++) {
			if (!open) b.push_back(a[j]);
			else b.back()^=a[j];
			if (a[j]&(1<<i)) open=!open;
		}
		if (!(x&(1<<i))) {
			if (open) {
				cout<<res<<"\n";
				return ;
			}
			a=b;
		} else {
			if (!open) res=max(res,(int)b.size());
		}
	}
	cout<<res<<"\n"; 
}
int main() {
	int t=1;
	cin>>t;
	while(t--) solve();
}