#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sqr(ll x) {
	return x*x;
}
struct Trie{
	struct Node{
		Node *child[26][26];
		int cnt;
		Node() {
			for (int i=0;i<26;i++) {
				for (int j=0;j<26;j++) child[i][j]=NULL;
			}
			cnt=0;
		}
	};
	Node *root;
	Trie() {
		root=new Node();
	}
	void add_string(string s) {
		Node *p=root;
		int n=(int)s.size();
		for (int i=0;i<n;i++) {
			int c1=s[i]-'a';
			int c2=s[n-i-1]-'a';
			if (p->child[c1][c2]==NULL) p->child[c1][c2]=new Node();
			p=p->child[c1][c2];
			p->cnt++;
		}
	}
	ll solve(Node *p,int depth) {
		ll res=(p==root?0: (ll)(p->cnt/2)*(sqr(depth)-sqr(depth-1)));
		for (int c1=0;c1<26;c1++) {
			for (int c2=0;c2<26;c2++){
				if (p->child[c1][c2]!=NULL) {
					res+=solve(p->child[c1][c2],depth+1);
				}
			}
		}
		return res;
	}
};
