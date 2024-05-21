#include<bits/stdc++.h>
using namespace std;
int constrainedSubsetSum(vector<int>& nums, int k) {
//        int n=nums.size();
//    deque<int> dq;
//    int res=0;
//    int s=0;
//    int i=0;
//    int pre=-1;
//    int largest=-1000000;
//    while (i<n) {
//    	largest=max(largest,nums[i]);
//    	while(!dq.empty()&&nums[dq.back()]<=nums[i]) dq.pop_back();
//    	dq.push_back(i);
//    	if (dq.front()+k<=i) dq.pop_front();
//    	if (dq.front()!=pre) {
//    	
//		 s+=nums[dq.front()];
//		 pre=dq.front();
//		}
//		i++;
//		
//	}
//	if (largest<=0) return  largest;
////	cout<<"tai s\n";
//	return s;
	int n=nums.size();
	deque<int> dq;
	int a[n+2]={0};
	for (int i=1;i<=n;i++) a[i]=nums[i-1];
	int dp[n+2]={0};
	dq.push_back(0);
	int res=-100000;
	int larges=-100000;
	for (int i=1;i<=n+1;i++) {
		while(!dq.empty()&&dq.front()+k<i) dq.pop_front();
		dp[i]=max(dp[dq.front()]+a[i],a[i]);
		if (i<=n)larges=max(larges,a[i]);
		cout<<"i="<<i<<"\tdp[dq.front()]="<<dp[dq.front()]<<"\tdp[i]="<< dp[i]<<endl;
		res=max(res,dp[i]);
		while(!dq.empty()&&dp[dq.back()]<=dp[i]) dq.pop_back();
		dq.push_back(i);
	}
	cout<<larges<<endl;
	if (larges<=0) return larges;
	return res;
}
int main() {
	int n,k; cin>>n>>k;
	vector<int> v;
	int x;
	for (int i=0;i<n;i++) {
		cin>>x; v.push_back(x);
	}
	cout<<constrainedSubsetSum(v,k);
}
