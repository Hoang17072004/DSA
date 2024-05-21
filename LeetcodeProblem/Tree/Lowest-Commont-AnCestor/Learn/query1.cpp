#include<bits/stdc++.h>
using namespace std;
const int N=17;
int par[N],up[N][17];
int w[N][N],dist[N][17];
int x;
void prepreocess() {
	for(int u=1;u<=n;u++) {
		up[u][0]=par[u];
		dist[u][0]+=w[u][par[u]];
	}
	for (int j=1;j<17;j++) {
		for (int u=1;u<=n;u++) {
			up[u][j]=up[up[u][j-1]][j-1];
			dist[u][j]=dist[up[u][j-1]][j-1];
		}
	}
}
int calc_dist(int u,int k) {
	int sum=0;
	for (int j=0;(1<<j)<=k;j++) {
		if (k>>j&1) {
			sum+=dist[u][j];
			u=up[u][j];
		}
	}
	return sum;
}
int solve(int u,int x) {
	int now_dist=0,k=0;
	for (int j=__lg(h[u]);j>=0;j--) {
		if (h[u]>=(1<<j)&&now_dist+dist[u][j]<=x) {
			now_dist+=dist[u][j];
			k|=1<<j;
			u=up[u][j];
		}
	}
	return u;
}
