#include<iostream>
#include<string>
using namespace std;
const int N=5010;
int n,d[N][N];
string ;
int calc(int i,int j) {
	//Nếu L[i,j] chưa được tính thì lưu giá trị vào d[i][j]
	if (d[i][j]==-1) {
		if (i>=j) d[i][j]=0;
		else {
			if (s[i]==s[j]) d[i][j]=calc(i+1,j-1);
			else d[i][j]=1+min(calc(i,j-1),calc(i+1,j));
		}
	}
	return d[i][j];
}
int main() {
	cin>>s;
	n=s.length();
	s="_"+s;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=n;j++) d[i][j]=-1;
	}
	cout<<calc(1,n)<<"\n";
}