#include<iostream>
#include<vector>
using namespace std;
const int N=1e3+10;
int f[N],a[N],d[N],n;
int main() {
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		f[i]=1;
		for (int j=1;j<i;j++) {
			if (a[j]<=a[i]&&f[i]<f[j]+1) {
				f[i]=f[j]+1;
				d[i]=j;
			}
		}
	}
	// Tìm t là vị trí cuối cùng của dãy dài nhất
	for (int i=1;i<=n;i++) if (f[i]>f[t]) t=i;
	//In ra dãy con đó
	vector<int> seq;
	while(t) {
		seq.push_back(t);
		t=d[t];
	}
	for (int x: seq) cout<<x<<" ";
}