#include<iostream>
using namespace std;
const int N=1e3+10;
int f[N],v[N],n,S;
//Gán f[i]=-1 nếu không thể tìm được một số đồng xu tổng bằng i
int main() {
	cin>>n>>S;
	for (int i=1;i<=n;i++) cin>>v[i];
	for (int i=1;i<=S;i++) {
		for (int j=1;j<=n;j++) {
			if (v[j]<=i&&f[i-v[j]]!=-1) {
				if (f[i]!=-1) f[i]=min(f[i],f[i-v[j]]+1);
				else f[i]=f[i-v[j]]+1;
			}
		}
		
	}
	cout<<f[S];
}