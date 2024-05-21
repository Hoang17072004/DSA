#include<bits/stdc++.h>
using namespace std;
const int NUMBEROFNODES=5400005;
const int LG=18;
struct Trie{
	struct Node{
		int child[2];
		int cnt;
	} nodes[NUMBEROFNODESS];
	int cur;
	Trie():cur(0) {
		memset(nodes[0].child,-1,sizeof(nodes[0].child));
		nodes[0].cnt=0;
	}
	int new_node() {
		cur++;
		memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
		nodes[cur].cnt=0;
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
	}
	int query(int x) {
		int pos=0,res=0;
		for (int i=LG;i>=0;i--) {
			int c=(x>>i)&1;
			if (nodes[pos].child[c]!=-1&&nodes[nodes[pos].child[c]].cnt==(1<<i)) {
				pos=nodes[pos].child[c^1];
				res+=(1<<i);
			} else pos=nodes[pos].child[c];
			if (pos==-1) break; 
		}
		return res;
	}
};
int main() {
	int n,m;
	cin>>n>>m;
	Trie trie;
	vector<int> v;
	for (int i=1;i<=n;i++) {
		int x; cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for (auto x: v) trie.add_number(x);
	int cur_xor=0;
	while(m--) {
		int x; cin>>x;
		cur_xor^=x;
		cout<<trie.query(cur_xor)<<"\n";
	}
}
