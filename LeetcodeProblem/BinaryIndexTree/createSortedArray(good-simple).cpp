class Solution {
public:
    static const int  n=100001;
    int c[n];
    int createSortedArray(vector<int>& instructions) {
        memset(c,0,sizeof(c));
        int res=0,mod=1e9+7;
        for (int i=0;i<instructions.size();i++) {
            res=(res+min(get(instructions[i]-1),i-get(instructions[i])))%mod;
            update(instructions[i]);
        }
        return res;
    }
    void update(int x) {
        while(x<n) {
            c[x]++;
            x+=(x&(-x));
        }
    }
    int get(int x) {
        int res=0;
        while(x>0) {
            res+=c[x];
            x-=(x&(-x));
        }
        return res;
    }
};
