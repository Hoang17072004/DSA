#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int MAXN=1e5+7;
int n,n,q;
int a[MAXN];
int st[4*MAXN];
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=a[l];
		return ;
	}
	 int mid=l+r>>1;
	 build(id*2,l,mid);
	 build(id*2+1,mid+1,r);
	 st[id]=min(st[2*id],st[2*id+1]);
}
void update(int id,int l,int r,int i,int val) {
	if (l>i||r<i) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=l+r>>1;
	update(2*id,l,mid,i,val);
	update(2*id+1,mid+1,r,i,val);
	st[id]=min(st[2*id],st[2*id+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return inf;
	if (l>=u&&r<=v) return st[id];
	int mid=l+r>>1;
	int get1=get(2*id,l,mid,u,v);
	int get2=get(2*id+1,mid+1,r,u,v);
	return min(get1,get2);
}
int main() {
	
}
