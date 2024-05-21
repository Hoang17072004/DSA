#include<bits/stdc++.h>
using namespace std;
long long continuousSubarrays(vector<int>& nums) {
    int n=nums.size();
    deque<int> dqmin;
    deque<int> dqmax;
    int j=0;
    long long res=0;
    for (int i=0;i<n;i++) {
    	while(!dqmin.empty()&&nums[dqmin.back()]>=nums[i]) dqmin.pop_back();
    	while(!dqmax.empty()&&nums[dqmax.back()]<=nums[i]) dqmax.pop_back();
    	dqmin.push_back(i); dqmax.push_back(i);
    	while(nums[dqmax.front()]-nums[dqmin.front()]>2) {
    		j++;
    		if (dqmax.front()<j) dqmax.pop_front();
    		if (dqmin.front()<j) dqmin.pop_front();
		}
		res+=i-j+1;
	}
	return res;
}
int main() {
	int n; cin>>n;
	vector<int> v;int x;
	for (int i=0;i<n;i++) {
		cin>>x;
		v.push_back(x);
	} 
	cout<<continuousSubarrays(v);
}
