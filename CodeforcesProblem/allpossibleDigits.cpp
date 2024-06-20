#include<bits/stdc++.h>
using namespace std;
int newdigit=-1;
bool check(set<int>&digit,int l,int r,bool usenewdigit) {
	for (int i=l;i<=r;i++) {
		if (usenewdigit&&i==newdigit) continue;
		if (!digit.count(i)) return false;
	}
	return true;
}
void solve() {
	int n,p; cin>>n>>p;
	int a[n+1]={0};
	set<int> digit;
	for (int i=1;i<=n;i++) cin>>a[i],digit.insert(a[i]);
	if (digit.size()==p) {
		cout<<"0\n"; return;
	}
	for (int i=n-1;i>=0;i--) {
		if (a[i]<p-1) {
			newdigit=a[i]+1;
			break;
		}
	}
	int l=0,r=p-1;
	int x=a[n];
	while(l<r) {
		int m=(l+r)/2;
		bool res=false;
		if (x+m>=p) {
			if (check(digit,x+m+1-p,x-1,true)) {
				res=true;
			}
		} else {
			if (check(digit,x+m+1,p-1,false)&&check(digit,0,x-1,false)) res=true;
		}
		if (res) r=m; else l=m+1;
	}
	cout<<l<<endl;
	
}
int main() {
	int t; cin>>t;
	while(t--) solve();
}