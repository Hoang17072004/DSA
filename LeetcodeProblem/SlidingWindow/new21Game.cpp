#include<bits/stdc++.h>
using namespace std;
double new21Game(int n, int k, int maxPts) {
	long  c[20001]={0};
	long s=1;
	c[1]=1;
	int t=k-1+maxPts;
	long e=0,f=0;
	int smaller=min(k,maxPts);
	for (int i=1;i<=smaller;i++) c[i]=1;
    for (int i=2;i<=t;i++) {
    	if (i>maxPts+1) s-=c[i-maxPts-1];
    	if (i<k) {
		 c[i]+=s;//+min(i-1,maxPts);
		 s+=c[i];
		 
		} else {
			
			c[i]=s;//+min(k-1,k-i+maxPts);
		}
		if (i>=k&&i<=n) e+=c[i];
		if (i>=k) f+=c[i];
    	cout<<"c["<<i<<"]="<<c[i]<<" ";
    	cout<<"\te="<<e<<"\tf="<<f<<endl;
    	//if (i>=k&&)
    	
	}
	return (double)e/f;
}
int main() {
	int n,k,maxPts; cin>>n>>k>>maxPts;
	cout<<new21Game(n,k,maxPts);
}
