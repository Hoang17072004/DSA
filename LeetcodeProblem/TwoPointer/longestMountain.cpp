#include<bits/stdc++.h>
using namespace std;
int longestMountain(vector<int>& arr) {
        int i=0;
        int res=0;
        int j=0;
        int k=0;
        cout<<"size="<<arr.size()<<endl;
        while(k<arr.size()) {
            i=max(i,k);
            while(i<arr.size()-1&&arr[i]<arr[i+1]) i++;
            j=max(j,i);
            while(j<arr.size()-1&&arr[j]>arr[j+1]) j++;
            res=max(res,j-k+1);
            cout<<"k="<<k<<"\ti="<<i<<"\tj="<<j<<endl;
            cout<<"arr[k]="<<arr[k]<<"\tarr[i]="<<arr[i]<<"\tarr[j]="<<arr[j]<<endl;
            if (j==5) break;
            if (i==5) break;
            if (k==5) break;
            if (j==arr.size()-1) break; 
            //return res;
            k=j;
        } 
        return res;
    }
int main() {
	vector<int> arr;
	for (int i=0;i<7;i++) {
		int x; cin>>x;
		arr.push_back(x);
	}
	longestMountain(arr);
}
