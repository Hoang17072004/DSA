#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,a,b,n,m;
	cin>>t;
	while(t--) {
		cin>>a>>b>>n>>m;
		int x,y;
		vector<pair<int,int>> ver;
		vector<pair<int,int>> hor;
		for (int i=0;i<n;i++) {
			cin>>x>>y;
			ver.emplace_back(x,y);
			hor.emplace_back(y,x);
		}
		sort(ver.begin(),ver.end());
		sort(hor.begin(),hor.end());
		int u=1,d=a,l=1,r=b;
		vector<int> ans(2,0);
		set<pair<int,int>> deleted;
		char c; int k;
		int vl=0,vr=n-1,hl=0,hr=n-1;
		for (int i=0;i<m;i++) {
			cin>>c>>k;
			if (c=='U') {
				u+=k;
				while(vl<=vr&&ver[vl].first<u) {
					if (deleted.find(ver[vl])==deleted.end()) {
						ans[i&1]++;
						deleted.insert(ver[vl]);
					}
					vl++;
				}
			} else if (c=='D') {
				d-=k;
				while(vl<=vr&&ver[vr].first>d) {
					if (deleted.find(ver[vr])==deleted.end()) {
						ans[i&1]++;
						deleted.insert(ver[vr]);
					}
					vr--;
				}
			} else if (c=='L') {
				l+=k;
				while(hl<=hr&&hor[hl].first<l) {
					if (deleted.find({hor[hl].second,hor[hl].first})==deleted.end()) {
						ans[i&1]++;
						deleted.insert({hor[hl].second,hor[hl].first});
					}
					hl++;
				}
			} else if (c=='R') {
				r-=k;
				while(hl<=hr&&hor[hr].first>r) {
					if (deleted.find({hor[hr].second,hor[hr].first})==deleted.end()) {
						ans[i&1]++;
						deleted.insert({hor[hr].second,hor[hr].first});
					}
					hr--;
				}
			}
		}
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
}