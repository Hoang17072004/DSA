class Solution {
public:
    map<pair<int,int>,bool> memo;
    vector<int> nums;
    int possibleSquareSide;
    bool recurse(int mask,int sidesDone) {
        int total=0;
        int L=nums.size();
        pair<int,int> memokey={mask,sidesDone};
        for (int i=L-1;i>=0;i--) {
            if ((mask&(1<<i))==0) {
                total+=nums[L-1-i];
            }
        }
        if (total>0&&total%possibleSquareSide==0) sidesDone++;
        if (sidesDone==3) return true;
        if (memo.find(memokey)!=memo.end()) return memo[memokey];
        bool ans=false;
        int c=total/possibleSquareSide;
        int rem=possibleSquareSide*(c+1)-total;
        for (int i=L-1;i>=0;i--) {
            if (nums[L-1-i]<=rem&&(mask&(1<<i))) {
                if (recurse(mask^(1<<i),sidesDone)) {
                    ans=true;
                    break;
                }
            }
        }
        memo[memokey]=ans;
        return ans;
    }
    bool makesquare(vector<int>& nums) {
        if (nums.size()==0) return false;
        int L=nums.size();
        int perimeter=0;
        for (int i=0;i<L;i++) perimeter+=nums[i];
        int possibleSquareSide=perimeter/4;
        if (possibleSquareSide*4!=perimeter) return false;
        this->nums=nums;
        this->possibleSquareSide=possibleSquareSide;
        return recurse((1<<L)-1,0);
    }
};