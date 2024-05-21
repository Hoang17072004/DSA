class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        long long lo=1,hi=1e17;
        while(hi>lo+1) {
            long long mid=(lo+hi)>>1;
            if (check(d1,d2,u1,u2,mid)) hi=mid;
            else lo=mid;
        }
        return hi;
    }
    bool check(long long d1,long long d2,long long u1,long long u2,long long x) {
        long long A=x/d1;
        long long A_=x-A;
        long long B=x/d2;
        long long B_=x-B;
        long long AIB=x/lcm(d1,d2);
        long long AuB=A+B-AIB;
        long long A_I_B_=x-AuB;
        long long needA=(A_-A_I_B_>=u1)?0:u1-(A_-A_I_B_);
        long long needB=(B_-A_I_B_>=u2)?0:u2-(B_-A_I_B_);
        return (A_I_B_>=needA+needB);
    }
};
