class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        int mod=1e9+7,ends0=0,ends1=0,has0=0;
        for (int i=0;i<binary.size();i++) {
            if (binary[i]=='1' ) ends1=(ends0+ends1+1)%mod;
            else {
                ends0=(ends0+ends1)%mod;
                has0=1;
            }
        }
        return (ends0+ends1+has0)%mod;
    }
};
