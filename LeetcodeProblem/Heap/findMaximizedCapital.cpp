#include<bits/stdc++.h>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> v;
        for (int i=0;i<profits.size();i++) {
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<pair<int,int>> pq;

    if (w<v[0].first) return 0;
    
    int i=0;
    while (i<v.size()&&v[i].first<=w) {
        
        pq.push({v[i].second-v[i].first,i});
        i++;
        //cout<<"1";
    }
    int s=w;
    while(!pq.empty()&&k) {
       //k--;
       // cout<<"2";
       //if (!pq.empty()) {
        w+=pq.top().first;
        s+=v[pq.top().second].second;
        k--;
        cout<<"w="<<w<<"\tpq.top()="<<pq.top().first<<endl;
        pq.pop();
      // }
        while(i<v.size()&&v[i].first<=w) {
            pq.push({v[i].second-v[i].first,i});
            i++;
        }
    }
    return s;
    }
int main() {
int k,w; cin>>k>>w;
int n,x; cin>>n;
vector<int> profits;
vector<int> capital;
for (int i=0;i<n;i++) {
	cin>>x;
	profits.push_back(x);
}
for (int i=0;i<n;i++) {
	cin>>x;
	capital.push_back(x);
}
cout<<findMaximizedCapital(k,w,profits,capital);

}
