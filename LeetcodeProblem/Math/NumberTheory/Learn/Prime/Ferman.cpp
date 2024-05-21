#include<bits/stdc++.h>
using namespace std;
//Tính a^k(mod n)
int binaryPower(long long a,int k,int n) {
	a=a%n;
	long long res=1;
	while(k) {
		if (k&1) res=(res*a)%n;
		a=(a*a)%n;
		k/=2;
	}
	return res;
}
bool isProbablyPrime(int n) {
	if (n<7) return n==2||n==3||n==5;
	static const int repeatNum=5;
	for (int i=0;i<repeatNum;i++) {
		int a=rand()%(n-3)+2;
		if (binaryPower(a,n-1,n)!=1) return false;
	}
	return true;
}
//Tính a*b mode n
long long binaryMul(long long a,long long b,long long n) {
	a=a%n;
	long long res=0;
	while(n) {
		if (b&1) res=(res+a)%n;
		a=(2*a)%n;
		b/=2;
	}
	return res;
}
//Tính a^b mod n
long long binaryPow(long long a,long long k,long long n) {
	a=a%b;
	long long res=1;
	while(k) {
		if (k&1) res=binaryMul(res,a,n);
		a=binaryMul(a,a,n)%n;
		k/=2;
	}
	return res;
}






