#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
const int MAXN=200200;
const int MAXK=MAXN;
const int MOD = 1000000007;
inline int add(int a,int b) {
	return (a+b>=MOD?a+b-MOD:a+b);
}
inline int mul(int a,int b) {
	return 1LL*a*b%MOD;
}
int n,m,k;
int arr[MAXN],brr[MAXN],cnt[MAXK];
void build() {
	sort(arr,arr+n);
	memcpy(brr,arr,sizeof(int)*n);
	k=unique(arr,arr+n)-arr;
	for (int j=0;j<k;j++) cnt[j]=upper_bound(brr,brr+n,arr[j])-lower_bound(brr,brr+n,arr[j]);
}
inline void push(stack<ipair> &S,int x) {
	S.emplace(x,mul(x,S.empty()?1:S.top().second));
}
int solve() {
	if (k<m) return 0;
	stack<ipair> S1,S2;
	for (int j=0;j<m;j++) push(S1,cnt[j]);
	int ans=0;
	for (int j=m;j<=k;j++) {
		if (arr[j-1]-arr[j-m]==m-1) ans=add(ans,mul(S1.empty()?1:S1.top().second,S2.empty()?1:S2.top().second));
		if (S2.empty()) {
			for (;!S1.empty();S1.pop()) push(S2,S1.top().first);
		}
		S2.pop();
		push(S1,cnt[j]);
	}
	return ans;
}
int main() {
	int t; cin>>t;
	while(t--) {
		cin>>n>>m;
		for (int i=0;i<n;i++) cin>>arr[i];
		build();
		cout<<solve()<<endl;
	}
}