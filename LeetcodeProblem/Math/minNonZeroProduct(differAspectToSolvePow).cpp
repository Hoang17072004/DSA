class Solution {
public:
    int mod=1e9+7;
    int minNonZeroProduct(int p) {
        long long val=(1ll<<p)-1;
        long long k=val/2;
        long long n=val-1;
        long long ans=expn(n,k);
        return (ans*(val%mod))%mod;
    }
    long long expn(long long n,long long k) {
        if (k==0) return 1;
        if (k==1) return n%mod;
        if (k%2==0) {
            long long temp=expn(n,k/2);
            return (temp*temp)%mod;
        } else {
            long long temp=expn(n,k/2);
            temp=(temp*temp)%mod;
            return (temp*(n%mod))%mod;
        }
    }
};
