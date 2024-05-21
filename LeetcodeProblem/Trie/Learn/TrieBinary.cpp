#include<bits/stdc++.h>
const int NUMBEROFNODES=...;
const int LG=...;
struct Trie{
	struct Node{
		int child[2];
		int exist,cnt;
	}nodes[NUMBEROFNODES];
	int cur=0;
	Trie():cur(0) {
		memset(nodes[0].child,-1,sizeof(nodes[0].child));
		nodes[0].exist=nodes[0].cnt=0;	
	}
	int new_node() {
		cur++;
		memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
		nodes[cur].exist=nodes[cur].cnt=0;
		return cur;
	}
	void add_number(int x) {
		int pos=0;
		for (int i=LG;i>=0;i--) {
			int c=(x>>i)&1;
			if (nodes[pos].child[c]==-1) nodes[pos].child[c]=new_node();
			pos=nodes[pos].child[c];
			nodes[pos].cnt++;
		}
		nodes[pos].exist++;
	}
	bool find_number(int x) {
		int pos=0;
		for (int i=LG;i>=0;i--) {
			int c=(x>>i)&1;
			if (nodes[pos].child[c]==-1) return false;
			pos=nodes[pos].child[c];
		}
		return (nodes[pos].exist!=0);
	}
	void delete_number(int x) {
		if (find_number(x)==false) return;
		int pos=0;
		for (int i=LG;i>=0;i--) {
			int c=(x>>i)&1;
			int tmp=nodes[pos].child[c];
			nodes[tmp].cnt--;
			if (nodes[temp].cnt==0) {
				nodes[pos].child[c]=-1;
				return;
			}
			pos=tmp;
		}
		nodes[pos].exist--;
	}
	int query(int x) {
		int pos=0,res=0;
		for (int i=LG;i>=0;i--) {
			int c=(x>>i)&1;
			if (nodes[pos].child[c^1]!=-1) {
				res+=(1ll<<i);
				pos=nodes[pos].child[c^1];
			} else pos=nodes[pos].child[c];
		}
		return res; 
	}
	
};
