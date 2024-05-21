#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Struct dùng để truy vết
struct Trace{
	//Vị trí của kí tự trươc đó trong A và B
	int i;
	int j;
	//Kí tự cần thêm vào xâu kết quả
	//(có thể là kí tự NULL)
	char c;
	Trace(int ii=0,int jj=0,char cc='\0'): i(ii),j(jj),c(cc) {
	}
	
};
int m,n;
strinng a,b;
vector<vector<int>> L;
vector<vector<Trace>> Tr;
int main() {
	cin>>a>>b;
	m=a.length();
	n=b.length();
	L.resize(m+1);
	Tr.resize(m+1);
	for (auto &i: L) i.resize(n+1);
	for (auto &i: Tr) i.resize(n+1);
	//Vì a và b bắt đầu từ chỉ số 1 nên
	//chèn thêm 1 kí tự vào đầu 2 xâu
	a="_"+a;
	b="_"+b;
	for (int i=0;i<=m;i++) L[i][0]=0;
	for (int j=0;j<=n;j++) L[0][j]=0;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			if (a[i]==b[j]) {
				L[i][j]=L[i-1][j-1]+1;
				Tr[i][j]=Trace(i-1,j-1,a[i]);
			} else if (L[i-1][j]>L[i][j-1]) {
				L[i][j]=L[i-1][j];
				Tr[i][j]=Trace(i-1,j);
			} else {
				L[i][j]=L[i][j-1];
				Tr[i][j]=Trace(i,j-1);
			}
			
		}
	}
	//Truy vết xâu con chung dài nhất từ Tr[m][n]
	Trace t=Tr[m][n];
	string ans="";
	while(true) {
		if (t.c!='\0') ans=t.c+ans;
		if (t.i==0&&t.j==0) break;
		else t=Tr[t.i][t.j];
	}
	cout<<ans;
}
//Cách cài đặt khách
vector<int> P(n+1),L(n+1);
for (int i=1;i<=m;i++) {
	L[0]=0;
	for (int j=1;j<=n;j++) {
		if (a[i]==b[j]) L[j]=P[j-1]+1;
		else L[j]=max(L[j-1],P[j]);
	}
	P=L;
}