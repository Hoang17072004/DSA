#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int a[n];
	vector<int> pre(n),suf(n);
	for (int i=0;i<n;i++) {
		cin>>a[i];
		pre[i]=a[i]+n-1-i;
		suf[i]=a[i]+i;
	}
	for (int i=1;i<n;i++) pre[i]=max(pre[i-1],pre[i]);
	for (int i=n-2;i>=0;i--) suf[i]=max(suf[i],suf[i+1]);
	int res=2e9;
	for (int i=0;i<n;i++) {
		int val=a[i];
		if (i) val=max(val,pre[i-1]);
		if (i<n-1) val=max(val,suf[i+1]);
		res=min(res,val);
	}
	cout<<res<<endl;
}