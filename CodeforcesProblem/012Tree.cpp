#include<bits/stdc++.h>
using namespace std;

int solve(int a,int b,int c) {
	int height=0;
	int node=1;
	while(a|b) {
		int p=node;
		if (a) {
			int t=min(a,node);
			a-=t; node+=t;
			p-=t;
		}
		if (p) {
			int t=min(b,p);
			b-=t; 
			p-=t;
		}
	
		height++;
	}

	if (node!=c) return -1;
	return height;
}
int main() {
	int t; cin>>t;
	int a,b,c;
	while(t--) {
		cin>>a>>b>>c;
		int t=solve(a,b,c);
		cout<<t<<endl;
	}
}