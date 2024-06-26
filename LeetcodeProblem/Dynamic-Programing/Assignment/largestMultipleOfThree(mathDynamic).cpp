class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int m1[]={1,4,7,2,5,8},m2[]={2,5,8,1,4,7};
        int sum=0,ds[10]={};
        for (int d: digits) {
            ds[d]++;
            sum+=d;
        }
        while(sum%3) {
            for (int i: sum%3==1? m1: m2) {
                if (ds[i]) {
                    ds[i]--;
                    sum-=i;
                    break;
                }
            }
        }
        string res="";
        for (int i=9;i>=0;i--) res+=string(ds[i],'0'+i);
        return res.size()&&res[0]=='0'?"0":res;
    }
};
