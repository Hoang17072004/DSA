//C1. Đệ quy
//Tính số cách sắp xếp n cái ghế
int solve(int n) {
	//Trường hợp cơ bản
	if (n==1) return 3;
	if(n==2) return 8;
	return 2*solve(n-1)+2*solve(n-2);
}
//C2.Memoration
int solve(int n) {
	if(n==1) return 3;
	else if (n==2) return 8;
	else if (d[n]!=0) return d[n];
	else {
		d[n]=2*f[n-1]+s*f[n-2];
		return d[n];
	}
}
//Dynamic Programing hoàn chỉnh
#include<iostream> 
using namespace std;
long long n,f[100010];
int main() {
	cin>>n;
	f[1]=3;
	f[2]=8;
	for (int i=3;i<=n;i++) f[i]=2*f[i-1]+2*f[i-2];
	cout<<f[n];
	return 0;
}