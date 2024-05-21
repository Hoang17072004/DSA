#include<bits/stdc++.h>
const int maxN=1e5+1;
int parent[maxN];
int sz[maxN];
void make_set(int v) {
	parent[v]=v;
	sz[v]=1;
}
int find_set(int v) {
	return v==parent[v]?v: parent[v]=find_set(parent[v]);
}
void union_sets(int a,int b) {
	a=find_set(a);
	b=find_set(b);
	if (a!=b) {
		if (sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
	}
}

