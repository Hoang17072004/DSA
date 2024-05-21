#include<bits/stdc++.h>
using namespace std;
int get_val(char f) {
	if (f=='A') return 0;
	if (f=='G') return 1;
	if (f=='C') return 2;
	return 3;
}
char get_char(int x) {
	if (x==0) return 'A';
	if (x==1) return 'G';
	if (x==2) return 'C';
	return 'U';
}
const int NUMBEROFNODES=2e6+5;
const int NUMBEROFNODES=2e6+5;
const int INF=1e9;
struct Trie{
	struct Node{
		int child[4];
		int l,r;
		int exist;
	}nodes[numberOfNodes];
	int cur;
	Trie():cur(0) {
		memset(nodes[0].child,-1,sizeof(nodes[cur].child));
		nodes[0].l=INF;nodes[0].r=-INF;
		nodes[0].exist=0;
	}
	int new_node() {
		cur++;
		memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
		nodes[cur].l=INF;nodes[cur].r=-INF;
		nodes[cur].exist=0;
		return cur;
	}
	void add_string(string s,int id) {
		int pos=0;
		for (auto f: s) {
			int c=get_val(f);
			if (nodes[pos].child[c]==-1) nodes[pos].child[c]=new_node();
			pos=nodes[pos].child[c];
			nodes[pos].l=min(nodes[pos].l,id);
			nodes[pos].r=max(nodes[pos].r,id);
		}
		nodes[pos].exist++;
	}
	pair<int,int> get_range(string s) {
		int pos=0;
		for (auto f: s) {
			int c=get_val(f);
			if (nodes[pos].child[c]==-1) return {-1,-1};
			pos=nodes[pos].child[c];
		}
		return {nodes[pos].l,nodes[pos].r};
	}
	void dfs(int pos,string &current_string,vector<string> &res) {
		for (int i=1;i<=nodes[pos].exist;i++) res.push_back(current_string);
		for (int i=0;i<4;i++) {
			if (nodes[pos].child[i]!=-1) {
				current_string+=get_char(i);
				dfs(nodes[pos].child[i],current_string,res);
				current_string.pop_back();
			}
		}
	}
	vector<string> sort_strings() {
		vector<string> res;
		string current_string="";
		dfs(0,current_string,res);
		return res;
	}
};
struct ReversedTrie{
	struct Node{
		int child[4];
		vector<int> ids;
	} nodes[NUMBEROFNODES];
	int cur;
	ReversedTrie():cur(0) {
		memset(nodes[0].child,-1,sizeof(nodes[cur].child));
		nodes[0].ids.clear();
	}
	int new_node() {
		cur++;
		memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
		nodes[cur].ids.clear();
		return cur;
	}
	void add_string(string s,int id) {
		reverse(s.begin(),s.end());
		int pos=0;
		for (auto f: s) {
			int c=get_val(f);
			if (node[pos].child[c]==-1) nodes[pos].child[c]=new_node();
			pos=nodes[pos].child[c];
			nodes[pos].ids.push_back(id);
		}
	}
	int query(string s,pair<int,int> range) {
		reverse(s.begin(),s.end());
		int pos=0;
		for (auto f: c) {
			int c=get_val(f);
			if (nodes[pos].child[c]==-1) return 0;
			pos=nodes[pos].child[c];
		}
		int l=lower_bound(nodes[pos].ids.begin(),nodes[pos].ids.end(),range.first)-nodes[pos].ids.begin();
		int r=upper_bound(nodes[pos].ids.begin(),nodes[pos].ids.end(),range.second)-nodes[pos].ids.begin()-1;
		return r-l+1;
	}
};
vector<string> sort_strings(vector<string> v){
	Trie list;
	for (auto s: v) list.add_string(s,-1);
	return list.sort_strings();
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<string>v;
	for (int i=1;i<=n;i++) {
		string s;
		cin>>s;
		v.push_back(s);
	}
	v=sort_strings(v);
	Trie trie1;
	ReversedTrie trie2;
	for (int i=1;i<=n;i++) {
		trie1.add_string(v[i-1],i);
		trie2.add_string(v[i-1],i);
	}
	while(m--) {
		string p,q;
		cin>>p>>q;
		pair<int,int> range=trie1.get_range(p);
		if (range.first==-1) cout<<"0\n";
		else cout<<trie2.query(q,range)<<"\n";
	}
}
