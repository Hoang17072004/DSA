#include<bits/stdc++.h>
using namespace std;
int boxDelivering(vector<vector<int> >& boxes, int portsCount, int maxBoxes, int maxWeight) {
        vector<pair<int,int> > a;
        int n=boxes.size();
        int j=0,i=0;
        while (i<n) {
            int s=0;
            //cout<<"Co co\n";
            while(j<n&&boxes[j][0]==boxes[i][0]) {
                if (s+boxes[j][1]>maxWeight||j-i+1>maxBoxes) {
                    a.push_back(make_pair(boxes[i][0],s));
                    s=0;
                    i=j;
                    //cout<<"haha\n";
                }
                s+=boxes[j][1];
               
                j++;
                //i=j;
            }
            //cout<<"i="<<i<<"\tj="<<j<<endl;
            
			a.push_back(make_pair(boxes[i][0],s));
			i=j;
            //i++;
        }
        int res=0;
        //deque<int> dq;
        j=0;i=0;
        while (i<a.size()) {
            //cout<<a[i].first<<"\t"<<a[i].second<<endl;
            int s=0,cnt=0;
            while(j<n&&j-i+1<=maxBoxes&&s<=maxWeight) {
            	s+=a[j].second;
            	res++;
            	j++;
			}
			res++;
			i=j;
            
        }
        return res;

}
int main() {

	int n; 
	int portsCount , maxBoxes, maxWeight;
	cin>>n>>portsCount>>maxBoxes>>maxWeight;
	vector<vector<int> > v(n, vector<int>(2));
	for (int i=0;i<n;i++) {
		for (int j=0;j<2;j++) cin>>v[i][j];
	}
	cout<<boxDelivering(v,portsCount,maxBoxes,maxWeight);

}
// 3
//2 3 3
//1 1
//2 1
//1 1

//5
//3 3 6
//1 2
//3 3
//3 1
//3 1
//2 4
