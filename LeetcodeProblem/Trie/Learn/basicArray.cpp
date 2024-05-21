#include<bits/stdc++.h>
using namespace std;
const int NUMBEROFNODES=...;
struct Trie{
	struct Node{
		int child[26];
		int exist,cnt;
	} nodes[NUMBEROFNODES];
	int cur;
	Trie(): cur(0) {
		memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
		nodes[0].exist=nodes[0].cnt=0;
	}
	int new_node() {
		cur++;
		memset(nodes[cur].child,sizeof(nodes[cur].child));
		nodes[cur].exist=nodes[cur].cnt=0;
		return cnt;
	}
	void add_string(string s) {
		int pos=0;
		for (auto f: s) {
			int c=f-'a';
			if (nodes[pos].child[c]==-1) {
				nodes[pos].child[c]=new_node();
			}
			pos=nodes[pos].child[c];
			nodes[pos].cnt++;
		}
		nodes[pos].exist++;
	}
	bool delete_string_recursive(int pos,string &s,int i) {
		if (i!=(int)s.size()) {
			int c=s[i]-'a';
			bool isChildDeleted=delete_string_recursive(nodes[pos].child[c],s,i+1);
			if (isChildDeleted) nodes[pos].child[c]=-1;
		} else nodes[pos].exist--;
		if (pos!=0) {
			nodes[pos].cnt--;
			if (nodes[pos].cnt==0) return true;
		}
		return false;
	}
	void delete_string(string s) {
		if (find_string(s)==false) return;
		delete_string_recursive(0,s,0);
	}
	bool find_string(string s) {
		int pos=0;
		for (auto f: s) {
			int c=f-'a';
			if (nodes[pos].child[c]==-1) return false;
			pos=nodes[pos].child[c];
		}
		return (nodes[pos].exist!=0);
	}
	void dfs(int pos,string &current_string,vector<string> &res) {
		for (int i=1;i<=nodes[pos].exist;i++) res.push_back(current_string);
		for (int i=0;i<26;i++) {
			if (nodes[pos].child[i]!=-1) {
				current_string+=char(i+'a');
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
	string find_kth_string(int k) {
		int pos=0;
		string res="";
		while(true) {
			if (nodes[pos].exist>=k) break;
			k-=nodes[pos].exist;
			for (int i=0;i<26;i++) {
				if (nodes[pos].child[i]!=-1) {
					int nxt=nodes[pos].child[i];
					if (nodes[nxt].cnt>=k) {
						res+=char(i+'a');
						pos=nxt;
						break;
					}
					k-=nodes[nxt].cnt;
				}
			}
		}
		return res;
	}
};
