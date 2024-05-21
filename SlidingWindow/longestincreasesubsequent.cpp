#include<bits/stdc++.h>
using namespace std;
//int lengthOfLIS(vector<int>& nums, int k) {
//    deque<int> dq;
//    //int res=0;
//    int n=nums.size();
//    int a[n+1]={0};
//    a[0]=1;
//    int res=1;
//    dq.push_back(0);
//    for (int i=1;i<n;i++) {
//    	while(!dq.empty()&&nums[dq.front()]>=nums[i]) dq.pop_front();
//    	while(!dq.empty()&&nums[dq.front()]+k<nums[i]) dq.pop_front();
//    	a[i]=1;
//    	if (!dq.empty()) {
//    		a[i]+=a[dq.front()];
//    		res=max(res,i-dq.front()+1);
//    		cout<<"i="<<i<<"\tdq.front()="<<dq.front()<<"\t";
//		}
//    	else {
//    		cout<<"i="<<i<<"\t";
//		}
//    	cout<<"a[i]="<<a[i]<<endl;
//    	
//    	while(!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
//    	//if (!dq.empty()&&a[dq.back()]==a[i]) continue;
//    	dq.push_back(i);
//	}
//	return res;
//}
int lengthOfLIS(vector<int>& nums, int k) {
	int n=nums.size();
    int a[n+1]={0};
    stack<int > st;
    int res=0;
    for (int i=0;i<n;i++) {
    	while(!st.empty()&&(nums[st.top()]>=nums[i]||nums[i]-nums[st.top()]>k)) st.pop();
    	if (st.empty()) {
    		cout<<"Khong co\ti="<<i;
			a[i]=1;
		}
    	else {
    		cout<<"front()="<<st.top()<<"\ti="<<i;
			a[i]=a[st.top()]+1;
		}
		cout<<"\ta[i]="<<a[i]<<endl;
    	res=max(res,a[i]);
    	st.push(i);
	}
	return res;
}
int main() {
	int n,k; cin>>n>>k;
	vector<int> v;int x;
	for (int i=0;i<n;i++) {
		cin>>x;
		v.push_back(x);
	}
	cout<<lengthOfLIS(v,k);
}
