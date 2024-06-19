#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		vector<int> a(n),b(n);
		for (int &x: a) cin>>x;
		for (int &x: b) cin>>x;
		
		vector<int> ord(n);
		iota(ord.begin(),ord.end(),0);
		sort(ord.begin(),ord.end(),[&](int i,int j){
			return b[i]>b[j];
		});
		
		long long f=0,p=0;
		for (int i: ord) p+=max(0,b[i]-a[i]);
		long long ans=0;
		multiset<int> s;
	
		if (s.size()==k) ans=max(ans,p-f);
 		for (int i: ord) {
			p-=max(0,b[i]-a[i]);
			s.insert(a[i]);
			f+=a[i];
			if (s.size()>k) {
				f-=*s.rbegin();
				s.erase(--s.end());
			}
			if (s.size()==k) ans=max(ans,p-f);
		}
		cout<<ans<<'\n';
	}
	
}