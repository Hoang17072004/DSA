class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        int sum=0;
        for (int num: machines) sum+=num;
        if (sum%n) return -1;
        int avg=sum/n;
        vector<int> leftsum(n,0),rightsum(n,0);
        for (int i=1;i<n;i++) leftsum[i]=leftsum[i-1]+machines[i-1];
        for (int i=n-2;i>=0;i--) rightsum[i]=rightsum[i+1]+machines[i+1];
        int move=0;
        for (int i=0;i<n;i++) {
            int expLeft=i*avg;
            int expRight=(n-1-i)*avg;
            int left=0;
            int right=0;
            if (expLeft>leftsum[i]) left=expLeft-leftsum[i];
            if (expRight>rightsum[i]) right=expRight-rightsum[i];
            move=max(move,left+right);
        }
        return move;
    }
};
