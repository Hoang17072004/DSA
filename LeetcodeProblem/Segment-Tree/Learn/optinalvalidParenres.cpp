#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
struct Node{
	int optimal;
	int open;
	int close;
	Node(){
	}
	Node(int optimal,int open,int close):optimal(optimal),open(open),close(close){
	}
	
};
Node operator +(const Node &left,const Node &right){
	Node res;
	int tmp=min(left.open,right.close);
	res.optimal=left.optimal+right.optimal+tmp*2;
	res.open=left.open+right.open-tmp;
	res.close=left.close+right.close-tmp;
	return res;
}
Node st[4*MAXN];
string s;
void build(int id,int l,int r) {
	if (l==r) {
		if (s[l]=='(') st[id]=Node(0,1,0);
		else st[id]=Node(0,0,1);
		return;
	}
	int mid=l+r>>1;
	build(2*id,l,mid);
	build(2*id+1,mid+1,r);
	st[id]=st[2*id]+st[2*id+1];
}
Node query(int id,int l,int r,int u,int v){
	if (v<l||r<u) return Node(0,0,0);
	if (l>=u&&r<=v) return st[id];
	int mid=l+r>>1;
	return query(2*id,l,mid,u,v)+query(2*id+1,mid+1,r,u,v);
}