#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
	int n=nums.size();
	deque<int> dqmin;
	deque<int> dqmax;
	int res=0;
	int l=0;
	for (int r=0;r<n;r++) {
		while(!dqmin.empty()&&nums[dqmin.back()]>=nums[r]) dqmin.pop_back();
		while(!dqmax.empty()&&nums[dqmax.back()]<=nums[r]) dqmax.pop_back();
		dqmin.push_back(r);
		dqmax.push_back(r);
		while(nums[dqmax.front()]-nums[dqmin.front()]>limit){
			l++;
			if (dqmax.front()<l) dqmax.pop_front();
			if (dqmin.front()<l) dqmin.pop_front();
		}
		res=max(r-l+1);
	}
	return res;
}
int main() {
	int n,limit; cin>>n>>limit;
	vector<int> v;
	int x;
	for (int i=0;i<n;i++) {
		cin>>x;
		v.push_back(x);
	}
	cout<<longestSubarray(v,limit);
}
