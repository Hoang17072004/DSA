#include<bits/stdc++.h>
using namespace std;
int left1,right1;
int binarysearch(vector<int> &a,int l,int r,int x) {
	if (l>r) {
		left1=r;
		right1=l;
		return -1;
	}
	int m=(l+r)/2;
	if (a[m]==x) {
		left1=right1=m;
		return m; 
	}
	if (x<a[m]) return binarysearch(a,l,m-1,x); 
	else return binarysearch(a,m+1,r,x);
}
void mersort(vector<int> &a,vector<int> &b,int l,int r,int x) {
	if (l<r) {
		int m=(l+r)/2;
		mersort(a,b,l,m,x);
		mersort(a,b,m+1,r,x);
		int i=l,j=m+1;
		int cnt=l;
		while(i<=m&&j<=r) {
			if (abs(a[i]-x)<=abs(a[j]-x)) {
				b[cnt++]=a[i];
				i++;
			} else  {
				b[cnt++]=a[j];
				j++;
			}
			
		}
		//cout<<"i="<<i<<"\tj="<<j<<endl;
			if (i>m) for (int k=j;k<=r;k++) b[cnt++]=a[k];
			else for (int k=i;k<=m;k++) b[cnt++]=a[k];
			//cout<<"sau sap xep\n";
			for (int k=l;k<=r;k++) {
				a[k]=b[k];
				//cout<<b[k]<<" ";
			}
//			cout<<endl;
//		cout<<"haha\t";
	}
} 
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int pos=binarysearch(arr,0,arr.size()-1,x);
    int l=left1,r=right1;
    //cout<<"pos="<<pos<<endl;
    vector<int> a; //vector<int> b(k);
    if (pos==-1&&(r==0||r==arr.size())) {
    	if (r==0) {
    		for (int i=0;i<k;i++) a.push_back(arr[i]);
    		return a;
		} else if (r==arr.size()) {
			for (int i=arr.size()-k;i<arr.size();i++) a.push_back(arr[i]);
			return a;
		} 
		}
		else  {
			
			//cout<<"l="<<l<<"\tr="<<r<<endl;
			for (int i=max(0,l-k+1);i<=l;i++) a.push_back(arr[i]);
			int t=min(r+k-1,(int)arr.size()-1);
			for (int i=(l!=r)?r:r+1;i<=t;i++) a.push_back(arr[i]);
			vector<int> b(a.size());
			//for (int i=0;i<a.size();i++) cout<<a[i]<<" ";cout<<endl;
			mersort(a,b,0,a.size()-1,x);
			//cout<<"xong mersort\n";
			vector<int> temp;
			for (int i=0;i<k;i++) temp.push_back(a[i]);
		//	for (int i=0;i<k;i++) cout<<temp[i]<<" "; cout<<endl<<"xong gan\n";
			sort(temp.begin(),temp.end());
			return temp;
		
	}
	//cout<<"ket thuc\n";
}
int main() {
	int n; cin>>n;int k,x;cin>>k>>x;
	vector<int> a;
	int h;
	for (int i=0;i<n;i++) {
		cin>>h;
		a.push_back(h);
	}
	vector<int> t=findClosestElements(a,k,x);
	for (int i=0;i<t.size();i++) cout<<t[i]<<" ";
}
