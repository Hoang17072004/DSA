#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n; cin>>n;
	string s; cin>>s;
	long long res=0;
	vector<long long> prefix(n,0);
	prefix[0]=s[0]-'0';
	for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+s[i]-'0';
	reverse(prefix.begin(),prefix.end());
	long long r=0;
	for (int i=0;i<n;i++) {
		int val=r+prefix[i];
		prefix[i]=val%10;
		r=val/10;
	}
	while(r) {
		prefix.push_back(r%10);
		r/=10;
	}
	int i=prefix.size()-1;
	while(i>=0&&prefix[i]==0) i--; 
	while(i>=0) cout<<prefix[i--];
	cout<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) {
		solve();
	}
}