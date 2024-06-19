#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	int n,k;
	while(t--) {
		cin>>n>>k;
		int i=0;
		while((1<<(i+1))<=k) i++;
		vector<int> ans={k-(1<<i),k+1,k+1+(1<<i)};
		for (int j=0;j<20;j++) {
			if (j!=i) ans.push_back(1<<j);
		}
		cout<<ans.size()<<endl;
		for (int x: ans) cout<<x<<" ";
		cout<<endl;
	}
}