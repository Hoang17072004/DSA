#include<bits/stdc++.h>
using namespace std;
int par[N],up[N][17];
void preprocess() {
	for (int u=1;u<=n;u++) up[u][0]=par[u];
	for (int j=1;j<17;j++) {
		for (int u=1;u<=n;u++) up[u][j]=up[up[u][j-1]][j-1];
	}
}
int ancestor_k(int u,int k) {
	for (int j=0;(1<<j)<=k;j++) {
		if (k>>j&1) u=up[u][j];
	}
	return u;
}
