#include<bits/stdc++.h>
using namespace std;

void solve() {
	int q; cin>>q;
	long long l=0,r=1e18;
//	vector<int> res;
	while(q--) {
		int t; cin>>t;
		if (t==1) {
			long long a,b,n; cin>>a>>b>>n;
			long long st=(n-2)*(a-b)+a+1;
			long long fi=(n-1)*(a-b)+a;
			if (n==1) st=1,fi=a;
			if (l>fi||r<st) cout<<0<<" "; else {
				l=max(l,st);
				r=min(r,fi);
				cout<<1<<" ";
			}
		} else {
			long long a,b; cin>>a>>b;
//			long long temp=max(0ll,l-a);
			long long st=max(1ll,1+(l-b-1)/(a-b));
//			temp=max(0ll,r-a);
			long long fi=max(1+(r-b-1)/(a-b),1ll);
//			cout<<"temp="<<temp<<",st="<<st<<",fi="<<fi<<endl;
			if (st!=fi) cout<<-1<<" "; else cout<<st<<" ";
		}
//		cout<<"["<<l<<","<<r<<"]\n";
	}
}
int main()  {
	int t; cin>>t;
	while(t--) solve();
}