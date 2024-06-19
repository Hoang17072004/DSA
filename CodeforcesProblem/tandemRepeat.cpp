#include<bits/stdc++.h>
using namespace std;
int main() {
	int t; cin>>t;
	string s;
	while(t--) {
		cin>>s;
		int ans=0;
		int n=s.size();
		for (int d=1;d<=n/2;d++) {
			int cnt=0;
			for (int i=0;i<n-d;i++) {
				if (s[i]==s[i+d]||s[i]=='?'||s[i+d]=='?') cnt++;
				if (i>=d&&(s[i]==s[i-d]||s[i]=='?'||s[i-d]=='?')) cnt--;
				if (i>=d-1&&cnt==d) ans=max(ans,2*d);  
			}
		}
		cout<<ans<<endl;
	}
}