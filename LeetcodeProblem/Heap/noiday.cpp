#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin>>n;
	int a[n];
	priority_queue<int,vector<int>,greater<int> > pq;
	for (int i=0;i<n;i++) {
		cin>>a[i];
		pq.push(a[i]);
	}
	int s=0;
	while(pq.size()>1) {
		int t=pq.top(); pq.pop();
		t+=pq.top(); pq.pop();
		pq.push(t);
		s+=t;
	}
	cout<<s;
	
	
}
