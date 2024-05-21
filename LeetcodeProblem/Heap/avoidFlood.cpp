#include<bits/stdc++.h>
using namespace std;
vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        set<int> dryday;
        map<int,int> fulllake;
        for (int i=0;i<rains.size();i++) {
            if (rains[i]==0) {
                ans.push_back(1);
                dryday.insert(i);
            } else {
                int lake=rains[i];
                if (fulllake.find(lake)!=fulllake.end()) {
                    auto it=dryday.lower_bound(fulllake[lake]);
                    if (it!=dryday.end()) {
                        int idx=*it;
                        ans[idx]=lake;
                        dryday.erase(it);
                    } else return {};

                }
                fulllake[lake]=i;
                ans.push_back(-1);

            }
        }
        return ans;
    }
int main() {
	vector<int> rains={1,3,2,0,2,0,3,0,1,0,0,0};
	vector<int> a=avoidFlood(rains);
	for (int i=0;i<a.size();i++) cout<<a[i]<<" ";
}