#include<bits/stdc++.h>
using namespace std;
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int d[n-1];
        for (int i=0;i<n-1;i++) d[i]=heights[i+1]-heights[i];
        //priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        int k=0;
        //int minuselader=min(ladders,n-2);
        int i=0;
        int s=0;
        int cnt=0;
        int negative=0;
        while (i<n-1) {
            cout<<"i="<<i<<endl;
            if (d[i]>0) {
                if (k<ladders) {
                k++;
                cout<<"lader "<<k<<endl;
                //maxheap.push(d[i]);
                minheap.push(d[i]);
                } else {
                    minheap.push(d[i]);
                    s+=minheap.top();
                    cout<<"sum use bricks= "<<s<<endl;
                    minheap.pop();
                    cout<<"s="<<s<<"\tcnt="<<cnt<<endl;
                    if (s<=bricks)cnt++;
                    
                    else break;
                    //maxheap.push(d[i]);
                    
                }
            } else {
                cout<<"jum down\n";
                negative++;

            }
            i++;
        }
        cout<<"\ncnt="<<cnt<<endl;
        cout<<"negative="<<negative;
        return negative+cnt+k;
    }
int main() {
	vector<int>heights={17,16,5,10,10,14,7};
	int bricks=74,ladders=6;
	cout<<furthestBuilding(heights,bricks,ladders);
}