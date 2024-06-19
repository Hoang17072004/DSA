#include<bits/stdc++.h>
using namespace std;
void solve(int n,string &s) {
	if (n%2==1) {
		cout<<-1<<endl;
		return;
	}
	vector<int> cnt(26);
	for (int i=0;i<n;i++) cnt[s[i]-'a']++;
	for (int i=0;i<26;i++) {
		if (cnt[i]*2>n) {
			cout<<-1<<endl;
			return;
		}
	}
	int pairs=0;
	vector<int> cnt_pairs(26);
	for (int i=0;i*2<n;i++) {
		if (s[i]==s[n-1-i]) {
			pairs++;
			++cnt_pairs[s[i]-'a'];
		}
	}
	for (int i=0;i<26;i++) {
		if (cnt_pairs[i]*2>pairs) {
			cout<<cnt_pairs[i]<<endl;
			return;
		}
	}
	cout<<(pairs+1)/2<<endl;
}
int main() {
	int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		string s; cin>>s;
		solve(n,s);
	}
}