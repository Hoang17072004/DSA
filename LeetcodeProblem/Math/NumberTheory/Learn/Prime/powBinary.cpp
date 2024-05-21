long long Pow(long long a,long long b) {
	if (!b) return 1;
	long long x=Pow(a,b/2);
	if (b%2==0) return x*x;
	else return x*x*a;
}
long long Pow(long long a,long long b) {
	long long ans=1;
	while(b>0) {
		if (b%2) ans=ans*a;
		a=a*a;
		b/=2;
	}
	return ans;
}
//Luy th?a chia l?y du
long long Pow(long long a,long long b,long long M) {
	long long ans=1;
	while(b>0) {
		if (b%2) ans=ans*a%M;
		a=a*a%M;
		b/=2;
	}
	return ans;
}
long long Mul(long long a,long long b) {
	if (!b) return 0;
	long long x=Mul(a,b/2);
	if (  b%2==0) return 2*x%m;
	else return (2*x+a)%m;
}