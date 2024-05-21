#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[]={6,3,6,2,3,1,9,8,6,5,3,2};
	priority_queue<int,vector<int>,greater<int> > pq;
	int n=sizeof(a)/sizeof(int);
	for (int i=0;i<n;i++) {
		if (pq.size()<4) pq.push(a[i]);
		else {
			if (pq.top()<a[i]) {
				pq.pop();
				pq.push(a[i]);
			}
		}
	}
	while(pq.size()) {
		cout<<pq.top()<<" ";
		pq.pop();
	}
}
