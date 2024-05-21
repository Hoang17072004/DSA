class Solution {
public:
    string fractionToDecimal(long long n, long long d) {
        if (n==0) return "0";
        string res;
        if (n<0^d<0) res+="-";
        n=abs(n);
        d=abs(d);
        res+=to_string(n/d);
        if (n%d==0) return res;
        res+=".";
        unordered_map<int,int> m;
        for (long long r=n%d;r;r%=d) {
            if (m.find(r)!=m.end()) {
                res.insert(m[r],"(",1);
                res+=")";
                break;
            }
            m[r]=res.size();
            r*=10;
            res+=to_string(r/d);
        }
        return res;
    }
};
