class Solution {
public:
    unordered_map<int,bool> m;
    vector<bool> used;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum=(1+maxChoosableInteger)*maxChoosableInteger/2;
        if (sum<desiredTotal) return false;
        if (desiredTotal<=0) return true;
        used.assign(maxChoosableInteger+1,0);
        return helper(desiredTotal);
    }
    bool helper(int desiredTotal) {
        if (desiredTotal<=0) return false;
        int key=format(used);
        if (m.find(key)==m.end()) {
            for (int i=1;i<used.size();i++) {
                if (!used[i]) {
                    used[i]=true;
                    if (!helper(desiredTotal-i)) {
                        m[key]=true;
                        used[i]=false;
                        return true;
                    }
                    used[i]=false;
                }
            }
            m[key]=false;
        }
        return m[key];
    }
    int format(vector<bool>&used) {
        int num=0;
        for (bool b: used) {
            num<<=1;
            if (b) num|=1;
        }
        return num;
    }
};
