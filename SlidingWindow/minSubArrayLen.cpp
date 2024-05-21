#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
       int i=0;
        int s=0;
        int n=nums.size();
        int res=1000000;
        for (int j=0;j<n;j++) {
            s+=nums[j];
            if (s==target) res=min(res,j-i+1);
            while(i<j&&s>target) {
            	s-=nums[i];
            	i++;
			}
			cout<<"s="<<s<<"\ti="<<i<<"\tj="<<j<<endl;
			if (s==target) res=min(res,j-i+1);
			else if (i>0&&s+nums[i-1]>=target) res=min(res,j-i+2);

        }
        if (res==1000000) return 0; return res;
}
int main() {
	int n,target; cin>>n>>target;
	vector<int> nums;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		nums.push_back(x);
	}
	cout<<minSubArrayLen(target,nums);
}
