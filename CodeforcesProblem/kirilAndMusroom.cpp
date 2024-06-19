#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll= long long;
void solve() {
	ll n;
	cin>>n;
	vector<ll> src(n);
	vector<pair<ll,ll>> can(n);
	for (ll i=0;i<n;i++) {
		cin>>src[i];
		can[i]={src[i],i};
	}
	vector<ll> ord(n);
	for (auto &item: ord) {
		cin>>item;
		item--;
	}
	sort(can.rbegin(),can.rend());
	ll best=can[0].first;
	ll take=1;
	ll cur;
	ll P=1;
	vector<bool> burn(n);
	vector<bool> used(n);
	used[can[0].second]=true;
	for (ll k=0;k+1<n&&P<n;k++) {
		while(P<n&&burn[can[P].second]) P++;
		if (P==n) break;
		used[can[P].second]=true;
		cur=can[P].first;
		P++;
		burn[ord[k]]=true;
		if (used[ord[k]]) {
			while(P<n&&burn[can[P].second]) P++;
			if (P==n) break;
			used[can[P].second]=true;
			cur=can[P].first;
			P++;
		}
		if (best<cur*(k+2)) {
			take=k+2;
			best=cur*(k+2);
		}
	}
	cout<<best<<' '<<take<<'\n';
}
int main() {
	ll testN;
	cin>>testN;
	while(testN--) {
		solve();
	}
}