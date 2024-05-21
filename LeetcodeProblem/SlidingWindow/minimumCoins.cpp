#include<bits/stdc++.h>
using namespace std;
int minimumCoins(vector<int>& prices) {
	
    int n=prices.size();
    deque<int> dq;
    int a[n+1]={0};
    dq.push_back(n);
    for (int i=n-1;i>=0;i--) {
    	while(dq.size()&&dq.front()>2*i+2) {
    		//cout<<"haha\n";
			dq.pop_front();
		}
    	
    	a[i]=prices[i];
    	//cout<<"i="<<i<<"\ta[i]="<<a[i]<<"\t";
    	if (dq.size()) {
    		//cout<<"front="<<dq.front()<<"\ta[dq.front()]="<<a[dq.front()];
			a[i]+=a[dq.front()];
		}
    	cout<<endl;
    	while(!dq.empty()&&a[dq.back()]>=a[i]) {
    		//cout<<"loai bo\n";
			dq.pop_back();
		}
	
    	dq.push_back(i);
//    	cout<<"dq.back()="<<dq.back()<<"\ta[dq.back()]="<<a[dq.back()]<<endl;
//    	cout<<"sau: dq.front()="<<dq.front()<<"\ta[dq.front()]="<<a[dq.front()]<<endl;
    	
	}
	//for (int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	return a[0];
}
int main() {
	int n; cin>>n;
	vector<int> v;
	int x;
	for (int i=0;i<n;i++) {
		cin>>x; v.push_back(x);
	}
	cout<<minimumCoins(v);
}
