#include<bits/stdc++.h>
using namespace std;
vector<int> bit1,bit2;
void updatePoint(vector<int> &b,int u,int v) {
	int idx=u;
	while(idx<=n) {
		b[idx]+=v;
		idx+=(idx&(-idx));
	}
}
void updateRange(int l,int r,int v) {
	updatePoint(bit1,l,(n-l+1)*v);
	updatePoint(bit1,r+1,-(n-r)*v);
	updatePoint(bit2,l,v);
	updatePoint(bit2,r+1,-v);
}
int getSumOnBIT(vector<int> &b,int u) {
	int idx=u,ans=0;
	while(idx>0) {
		ans+=b[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
int prefixSum(int u) {
	return getSumOnBIT(bit1,u)-getSumOnBIT(bit2,u)*(n-u);
}
int rangeSum(int l,int r) {
	return prefixSum(r)-prefixSum(l-1);
}
