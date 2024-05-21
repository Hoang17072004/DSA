#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+1;
int prefix[maxN];
int bit[maxN];
int a[maxN];
int n;
void precompute() {
	for (int i=1;i<=n;i++) {
		prefix[i]=prefix[i-1]+a[i];
	}
	for (int i=1;i<=n;i++) {
		int t=i&(-i);
		cout<<"t="<<t<<endl;
		bit[i]=prefix[i]-prefix[i-t-1];
	}
}
int getSum(int p) {
	int idx=p,ans=0;
	while(idx>0) {
		ans+=bit[idx];
		idx-=(idx&(-idx));
	}
	return ans;
}
void update(int u,int v) {
	int idx=u;
	while(idx<=n) {
		bit[idx]+=v;
		idx+=(idx&(-idx));
	}
}
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	precompute();
	update(4,5);
	cout<<getSum(4);
}
