#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
int N;
int x[MAXN],y[MAXN],r[MAXN];
int clr[MAXN];
int cnt[2];
long long sqr(int val) {
	return (ll)val*val;
}
bool dfs(int i, int c) {
	if (clr[i]!=-1) return clr[i]==c;
	cnt[c]++;
	bool res=true;
	clr[i]=c;
	for (int j=0;j<N;j++) {
		if (sqr(x[i]-x[j])+sqr(y[i]-y[j])==sqr(r[i]+r[j])) res&=dfs(j,c^1);
	}
	return res;
}
int main() {
	cin>>N;
	for (int i=0;i<N;i++) {
		cin>>x[i]>>y[i]>>r[i];
		clr[i]=-1;
	}
	for (int i=0;i<N;i++) {
		if (clr[i]==-1){
			memset(cnt,0,sizeof(cnt));
			if (dfs(i,0)&&cnt[0]!=cnt[1]) {
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
}