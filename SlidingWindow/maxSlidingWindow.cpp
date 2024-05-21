#include<bits/stdc++.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        vector<int> v;
        //int s=0;
        int res=-1000000;//start=0,end=0;
        for (int i=0;i<n;i++) {
            if(dq.size()&&dq.front()+k<=i) {
               // s-=nums[dq.front()];
                dq.pop_front();
            }
            //s+=nums[i];
            while(dq.size()&&nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) {
                //res=max(res,s);// start=dq.front();
                //end=i;
                v.push_back(nums[dq.front()]);
            }
            


        }
        
//        cout<<"start="<<start<<"\tend="<<end<<endl;
        //for (int i=start;i<=end;i++) v.push_back(nums[i]);
        return v;
}
int main() {
	int n,k; cin>>n>>k;
	vector<int> nums;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		nums.push_back(x);
	}
	vector<int> v=maxSlidingWindow(nums,k);
	for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
}
