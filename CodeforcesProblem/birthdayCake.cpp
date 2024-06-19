#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,x,y; cin>>n>>x>>y;
	int initial_y=y;
	vector<int> chosen(x);
	for (int &i: chosen) cin>>i;
	sort(chosen.begin(),chosen.end());
	int ans=x-2;
	int triangles_from_even_g=0;
	vector<int> odd_g;
	auto process_gap=[&](int g)->void{
		if (g<=1) ans+=g;
		else if (g%2==1) odd_g.push_back(g/2);
		else triangles_from_even_g+=g/2;
	};
	for (int i=0;i<x-1;i++) {
		process_gap(chosen[i+1]-chosen[i]-1);
	}
	process_gap(chosen[0]+n-chosen[x-1]-1);
	sort(odd_g.begin(),odd_g.end());
	for (int g: odd_g) {
		if (y>=g) {
			ans+=g+1;
			y-=g;
		} else {
			ans+=y;
			y=0;
			break;
		}
	}
	int even_trianges=min(triangles_from_even_g,y);
	y-=even_trianges;
	ans+=even_trianges;
	int used_vertices=initial_y-y;
	ans+=used_vertices;
	cout<<ans<<"\n";
}
int main() {
	int T=1;
	cin>>T;
	while(T--) solve();
}