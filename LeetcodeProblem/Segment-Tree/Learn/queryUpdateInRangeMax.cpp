#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int maxN=1e5+7;
int n,q;
int a[maxN];
long long st[4*maxN],lazy[4*maxN];
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	st[id]=max(st[2*id],st[2*id+1]);
}
void fix(int id,int l,int r) {
	if (!lazy[id]) return;
	st[id]+=lazy[id];
	if (l!=r) {
		lazy[2*id]+=lazy[id];
		lazy[2*id+1]+=lazy[id];
	}
	lazy[id]=0;
	
}
void update(int id,int l,int r,int u,int v,int value) {
	fix(id,l,r);
	if (l>v||r<u) return;
	if (l>=u&&r<=v) {
		lazy[id]+=value;
		fix(id,l,r);
		return;
	}
	int mid=l+r>>1;
	update(2*id,l,mid,u,v,value);
	update(2*id+1,mid+1,r,u,v,value);
	st[id]=max(st[2*id],st[2*id+1]);
}
long long get(int id,int l,int r,int u,int v){
	fix(id,l,r);
	if (l>v||r<u) return -inf;
	if (l>=u&&r<=v) return st[id];
	int mid=l+r>>1;
	long long get1=get(2*id,l,mid,u,v);
	long long get2=get(2*id+1,mid+1,r,u,v);
	return max(get1,get2);
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>q;
	while(q--) {
		int type,l,r,value;
		cin>>type>>l>>r;
		if (type==1) {
			cin>>value;
			update(1,1,n,l,r,value);
		}
		else cout<<get(1,1,n,l,r)<<endl;
	}
}