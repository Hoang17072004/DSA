class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int n=A.size(),m=n/2,totalSum=accumulate(A.begin(),A.end(),0);
        sort(A.rbegin(),A.rend());
        for (int i=1;i<=m;i++) {
            if (totalSum*i%n==0&&combinationSum(A,0,i,totalSum*i/n)) return true;
        }
        return false;
    }
    //this function use backtracking to find the sequent with k elements ans sum equal t
    // the trick here is sort the array by decending order and end the function soon when
    //you meet the condidtion in row 16
    bool combinationSum(vector<int>&nums,int idx,int k,int tar) {
        if (k==0) return tar==0;
        if (tar>nums[idx]*k) return false;//this is the very important trick to improve performent
        for (int i=idx;i<=nums.size()-k;i++) {
            if (nums[i]<=tar&&combinationSum(nums,i+1,k-1,tar-nums[i])) return true;
        }
        return false;
    }
};
