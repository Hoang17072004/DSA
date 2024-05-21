#include<bits/stdc++.h>
using namespace std;
int findMaxValueOfEquation(vector<vector<int> >& points, int k) {
        int n=points.size();
        deque<int>dq;
        int res=-1000000001;
        for (int i=0;i<n;i++) {
            
            while (!dq.empty()&&points[dq.front()][0]+k<points[i][0]) dq.pop_front();
            if (!dq.empty()) res=max(res,points[i][0]+points[i][1]+points[dq.front()][1]-points[dq.front()][0]);
            while(!dq.empty()&&points[dq.back()][1]-points[dq.back()][0]<=points[i][1]-points[i][0]) dq.pop_back();
            dq.push_back(i);
        }
        return res;
}
int main() {
	int n,k; cin>>n>>k;
	vector<vector<int> > v(n, vector<int>(2));
	for (int i=0;i<n;i++) {
		for (int j=0;j<2;j++) cin>>v[i][j];
	}
	cout<<findMaxValueOfEquation(v,k);
}
