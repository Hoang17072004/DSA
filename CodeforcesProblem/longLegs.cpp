#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	while(t--) {
		int a,b; cin>>a>>b;
		int ans=a+b;
		for (int m=1;m<100000;m++) {
			ans=min(ans,(a+m-1)/m+(b+m-1)/m+m-1);
		}
		cout<<ans<<endl;
	}
}