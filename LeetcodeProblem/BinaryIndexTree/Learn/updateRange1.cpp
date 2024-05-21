#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
int diff[maxN+1];
int a[maxN+1];
int bit[maxN+1];
void precompute() {
	diff[1]=a[1];
	for (int i=2;i<=n;i++) diff[i]=a[i]-a[i-1];
	for (int i=1;i<=n;i++) {
		int t=i&(-i);
		bit[i]=a[i]-a[i-t-1];
	}
}
void updatePoint(int u,int v) {
	int idx=u;
	while(idx<=n) {
		bit[idx]+=v;
		idx+=(idx&(-idx));
	}
}
void updateRange(int l,int r,int v) {
	updatePoint(l,v);
	updatePoint(r+1,-v);
}
int get(int u) {
	int idx=u,ans=0;
	while(idx>0) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}

