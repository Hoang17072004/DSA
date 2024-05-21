#include<iostream>
#include<cmath>
using namespace std;
struct Point{
	double x;
	double y;
	Point(double xx=0,double yy=0) :x(xx),y(yy){
	}
};
double distance(const Point&a,const Point&b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
const int N=310;
int n;
double L[N][N];
Point p[N];
int main() {
	cint>>n;
	for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	for (int dis=3;dis<=n-1;dis++) {
		for (int i=1;i+dis<=n;i++) {
			int j=i+dis;
			L[i][j]=L[i+1][j]+distance(p[i+1],p[j]);
			for (int k=i+1;k<=j-1;k++) {
				L[i][j]=min(L[i][j],L[i][k]+L[k+1][j]+distance(p[i],p[k])+distance(p[k],p[j]));
			}
		}
		
	}
	cout<<L[1][n];
}