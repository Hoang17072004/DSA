#include<bits/stdc++.h>
using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    deque<int> dqmin;
    deque<int> dqmax;
    int n=nums.size();
    for (int i=0;i<n;i++) {
    	while(dqmin.size()&&dqmin.front()+indexDiff<i) dqmin.pop_front();
    	while(dqmax.size()&&dqmax.front()+indexDiff<i) dqmax.pop_front();
    	//int tmin=0,tmax=0;
		
    	
    	if (dqmin.size()&&abs(nums[i]-nums[dqmin.front()])<=valueDiff) return true;
    	if (dqmax.size()&&abs(nums[i]-nums[dqmax.front()])<=valueDiff) return true;
    	
		//if (dqmin.size()&&dqmax.size()&&  dqmin.front()!=dqmax.front()&&nums[dqmax.front()]-nums[dqmin.front()]<=valueDiff) return true;
    	while(dqmin.size()&&nums[dqmin.back()]>=nums[i]) {
			//tmin=dmin.back();
			dqmin.pop_back();
		}
    	while(dqmax.size()&&nums[dqmax.back()]<=nums[i]) {
    		//tmax=dmax.back();
			dqmax.pop_back();
		}
    	dqmin.push_back(i); dqmax.push_back(i);
    	
	}
	return false;
}
int main() {
	int n;int indexDiff; int valueDiff;
	cin>>n>>indexDiff>>valueDiff;
	vector<int> nums;
	int x;
	for (int i=0;i<n;i++) {
		cin>>x;nums.push_back(x);
	}
	cout<<containsNearbyAlmostDuplicate(nums,indexDiff,valueDiff);
}
