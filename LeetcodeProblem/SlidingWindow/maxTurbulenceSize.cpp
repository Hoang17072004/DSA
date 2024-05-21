#include<bits/stdc++.h>
using namespace std;
//int maxTurbulenceSize(vector<int>& arr) {
//    int d[arr.size()]={0};
//    d[0]=arr[0];
//    for (int i=1;i<arr.size();i++) d[i]=arr[i]-arr[i-1];
//    int negative=0,positive=0;
//    int i=0;
//    int res=1;
//    for (int i=0;i<arr.size();i++) cout<<d[i]<<" ";
//	cout<<endl;
//    for (int j=1;j<arr.size();j++) {
//    	if (d[j]<0) negative++;
//    	 if (d[j]>0) positive++;
//		 if (d[j]==0) {
//		 	i=j; negative=positive=0;
//		 }
//    	 //if (j&&d[j-1]==0 i=j;
//    	
//    	while (i<j&&abs(negative-positive)>1) {
//    		cout<<"Tron lap:i="<<i<<"\tj="<<j<<"\tpositive="<<positive<<"\tnegative="<<negative<<endl;
//    		if (d[i+1]>0) positive--;
//    		if (d[i+1]<0) negative--;
//    		i++;
//		}
//		cout<<"i="<<i<<"\tj="<<j<<"\tpositive="<<positive<<"\tnegative="<<negative<<endl;
//    	res=max(res,j-i+1);
//	}
//	
//	return res;
//}
int maxTurbulenceSize(vector<int> &arr) {
	if (arr.size()==1) return 1;
	int d[arr.size()-1]={0};
	for (int i=0;i<arr.size()-1;i++) d[i]=arr[i+1]-arr[i];
	int j=0,i=0;
	int res=1;
	for (int i=0;i<arr.size()-1;i++) cout<<d[i]<<" ";cout<<endl;
	while (i<arr.size()-1) {
		//cout<<"haha";
		while(d[i]==0) {
			i++;j++;
		}
		
		while (j+1<arr.size()-1&&d[j+1]*d[j]<0) j++;
		//cout<<"i="<<i<<"\tj="<<j<<endl;
		if (d[j]&&d[i]) res=max(res,j-i+2);
		j++;
		i=j;
		
	}
	return res;
}
int main()  {
	int n; cin>>n; int x;
	vector<int> arr;
	for (int i=0;i<n;i++) {
		cin>>x; arr.push_back(x);
		
	}
	cout<<maxTurbulenceSize(arr);
}
