#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+5;
int parent[maxN],sz[maxN],disc[maxN];
void make_set(int v) {
	parent[v]=v;
	sz[v]=1;
	disc[v]=0;
}
pair<int,int> find_set(int v) {
	if (v==parent[v]) return {v,0};
	pair<int,int>val=find_set(parent[v]);
	parent[v]=val.first;
	disc[v]=(disc[v]+val.second)%2;
	return {parent[v],disc[v]};
}
void union_sets(int a,int b) {
	pair<int,int> valA=find_set(a);
	pair<int,int> valA=find_set(a);
	pair<int,int> valB=find_set(b);
	a=valA.first;b=valB.first;
	if(a==b) {
		if (valA.second!=valB.second) {
			// The grapth isn't a two directed grapth 
			//the edge between two node belong two different site
		}
	} else {
		if (sz[a]<sz[b]) swap(a,b);
		parent[b]=a;
		sz[a]+=sz[b];
		disc[b]=(valA.second+valB.second+1)%2;
	}
}
