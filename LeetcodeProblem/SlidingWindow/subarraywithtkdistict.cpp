#include<bits/stdc++.h>
using namespace std;
int subarraywithmostkdistict(vector<int> &nums,int k) {
        int i=0;
        map<int,int> m;

        int cnt=0;
        int res=0;
        for (int j=0;j<nums.size();j++) {
            m[nums[j]]++;
            if(m[nums[j]]==1) cnt++;
            while(cnt>k) {
                m[nums[i]]--;
                if (m[nums[i]]==0) cnt--;
                i++;
            }
            res+=j-i+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a=subarraywithmostkdistict(nums,k);
        int b=subarraywithmostkdistict(nums,k-1);
        return a-b;
    }
int main() {
	
}
