#include<bits/stdc++.h>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    long long s=1;
    int i=0;
    int ans=0;
    for (int j=0;j<nums.size();j++) {
    	s*=nums[j];
    	while(i<=j&&s>=k) {
    		s/=nums[i];
    		i++;
		}
		//cout<<"s="<<s<<"\ti="<<i<<"\tj="<<j<<endl;
		ans+=j-i+1;
	}
	return ans;
}
int main() {
	int n,k; cin>>n>>k;
	vector<int> nums;
	int x;
	for (int i=0;i<n;i++) {
		cin>>x;
		nums.push_back(x);
	}
	cout<<numSubarrayProductLessThanK(nums,k);
}
