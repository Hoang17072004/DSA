#include<bits/stdc++.h>
using namespace std;
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int s=startFuel;
        int pre=0;
        int n=stations.size();
        int cnt=0;
        priority_queue<int> pq;
        for (auto station: stations) {
            int position=station[0];
            int fuel=station[1];
            s-=position-pre;
            while(!pq.empty()&&s<0) {
                s+=pq.top();
            pq.pop();
                cnt++;
            }
            pq.push(fuel);
            if (s<0) return -1;
            pre=position;
        }
        s-=target-pre;
        while(!pq.empty()&&s<0) {
            s+=pq.top();
            cnt++;
            pq.pop();
        }
        if (s<0) return -1; 
        return cnt;
    }
int main() {
	int target=100,startFuel=50;
	vector<vector<int>> stations={{25,50},{50,25}};
	cout<<minRefuelStops(target,startFuel,stations);
}