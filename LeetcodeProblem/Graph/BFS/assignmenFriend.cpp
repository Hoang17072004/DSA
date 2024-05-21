#include<stdio.h>
using namespace std;
int cach1(int n) {
	if (n==0 ) return 1;
	if (n==1) return 3;
	return 2*cach1(n-1)+3*cach1(n-2);
}  
int cach2(int n) {
	int a=1,b=3;
	if (n==0) return a;
	if (n==1) return b;
	int c=0;
	for (int i=2;i<=n;i++) {
		c=2*b+3*a;
	
		a=b;
		b=c;
	}
	return c;
}
int main() {
	printf("%d\n",cach1(5));
	printf("%d\n",cach2(5));
}