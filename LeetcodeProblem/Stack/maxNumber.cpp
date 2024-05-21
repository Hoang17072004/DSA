#include<bits/stdc++.h>
using namespace std;
vector<int> maxkdigit(vector<int> &nums,int k) {
        stack<int> s;
        for (int i=0;i<nums.size();i++) {
            while(s.size()&&k-s.size()<nums.size()-i &&s.top()<nums[i]) {
                s.pop();
            }
            if (s.size()<k) s.push(nums[i]);
        }
        vector<int> res;
        while(s.size()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int comp(vector<int> &a,vector<int> &b) {
        if (a.size()<b.size()) return -1;
        if (a.size()>b.size()) return 1;
        for (int i=0;i<a.size();i++) if (a[i]>b[i]) return 1; else if (a[i]<b[i]) return -1;
        return 0;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int firstlength= min((int)nums1.size(),k);
        vector<int> a,b,temp,res(0);
        for (int i=0;i<=firstlength;i++) {
            a=maxkdigit(nums1,i);
            
            int secondlength=min(k-i,(int)nums2.size());
            b=maxkdigit(nums2,secondlength);
           
            int l1=0,l2=0;
            temp.clear();
            while(l1<i&&l2<secondlength) {
                if (a[l1]>b[l2] ){
                    temp.push_back(a[l1]);
                    l1++;
                } else if (a[l1]<b[l2]) {
                    temp.push_back(b[l2]);
                    l2++;
                } else {
                    int idx1=l1,idx2=l2;
                    while(idx1<a.size()&&idx2<b.size()&&a[idx1]==b[idx2]) {
                        idx1++; idx2++;
                    } 
                    if (idx2==b.size()) {
                        temp.push_back(a[l1]); l1++;
                    } else {
                        if (idx1<a.size()&&a[idx1]>b[idx2]) {
                            temp.push_back(a[l1]); l1++;
                        } else {
                            temp.push_back(b[l2]); l2++;
                        }
                    }
                }
            }
            if (l1==i) for (int j=l2;j<secondlength;j++) temp.push_back(b[j]);
            else for (int j=l1;j<i;j++) temp.push_back(a[j]);
           
            
            if (comp(res,temp)==-1) res=temp;
           
        }

      
        
        return res;
        
    }
int main() {
	vector<int> nums1={3,4,6,5};
	vector<int> nums2={9,1,2,5,8,3};
	int k=5;
	maxNumber(nums1,nums2,k);
}