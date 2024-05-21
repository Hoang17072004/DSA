#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int MAXN=1e5+7;
int n,q;
int a[MAXN],st[4*MAXN];
void update(int id,int l,int r,int i,int val) {
	if (i<l||i>r) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=l+r>>1;
	update(id*2,l,mid,i,val);
	update(id*2+1,mid+1,r,i,val);
	st[id]=st[2*id]+st[2*id+1];
}
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (l>=u&&r<=v) return st[id];
	int mid=l+r>>1;
	int get1=get(id*2,l,mid,u,v);
	int get2=get(id*2+1,mid+1,r,u,v);
	return get1+get2;
}
int main() {
	cin>>n>>q;
	while(q--) {
		int type,x,y;
		cin>>type>>x>>y;
		if (type==1) update(1,1,n,x,y);
		else cout<<get(1,1,n,x,y)<<endl;
	}
}
