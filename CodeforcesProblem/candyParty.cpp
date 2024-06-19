#include<bits/stdc++.h>
using namespace std;
bool solve() {
	int n; cin>>n;
	int a[n];
	long long s=0;
	for (int i=0;i<n;i++) cin>>a[i],s+=a[i];
	if (s%n) return false;
	s/=n;
	vector<int> bit(31,0);
	auto lowbit=[](int x) {
		return x&(-x);
	};
	for (int i=0;i<n;i++) {
		if (a[i]==s) continue;
		int d=abs(s-a[i]);
		int p=lowbit(d);
		int e=d+p;
		if (__builtin_popcount(e)==1) {
			if (a[i]>s) bit[__lg(p)]--,bit[__lg(e)]++;
			else bit[__lg(e)]--,bit[__lg(p)]++;
		} else {
			return false;
		}
	}
	for (int i=0;i<=30;i++) if (bit[i]) return false;
	return true;
}
int main() {
	int t; cin>>t;
	while(t--) if(solve()) cout<<"Yes\n"; else cout<<"No\n"; 
}