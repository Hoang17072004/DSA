#include<bits/stdc++.h>
using namespace std;
int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
	int ans=0;
	queue<int> q;
	for (int i=0;i<n;i++) {
        

		int pivot=q.size()%2==0?nums[i]:1-nums[i];
		if (pivot==0) {
			ans++;
			q.push(i+k-1);
		}
        if (!q.empty()&&q.front()==i) q.pop();
		}      
	return q.empty()?ans:-1;
    }int main() {
	
}
