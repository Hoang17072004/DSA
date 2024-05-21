#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int maxN=1e4+7;
int n,m;
int a[maxN];
multiset<int> st[4*maxN];
void build(int id,int l,int r) {
	if (l==r) {
		st[id].insert(a[l]);
		return;
	}
	int mid=l+r>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	for (int x:st[2*id]) st[id].insert(x);
	for (int x: st[2*id+1]) st[id].insert(x);
}
void update(int id,int l,int r,int i,int value) {
	if (l>i||r<i) return;
	if (l==r) {
		st[id].clear();
		st[id].insert(value);
		return;
	}
	int mid=l+r>>1;
	update(2*id,l,mid,i,value);
	update(2*id+1,mid+1,r,i,value);
	st[id].erase(st[id].find(a[i]));
	st[id].insert(value);
}
int get(int id,int l,int r,int u,int v,int k) {
	if (l>v||r<u) return inf;
	if (l>=u&&r<=v) {
		auto it=st[id].lower_bound(k);
		if (it==st[id].end()) return inf;
		return *it;
	}
	int mid=l+r>>1;
	int get1=get(2*id,l,mid,u,v,k);
	int get2=get(2*id+1,mid+1,r,u,v,k);
	return min(get1,get2);
}
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--) {
		int type,l,r,k;
		cin>>type;
		if (type==1) {
			cin>>l>>k;
			update(1,1,n,l,k);
			a[l]=k;
		}  else {
			cin>>l>>r>>k;
			int ans=get(1,1,n,l,r,k);
			if (ans==inf) cout<<-1<<endl; else cout<<ans<<endl;
		}
	}
}