#include<bits/stdc++.h>
using namespace std;
vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> working;
        
        set<int> preworker;
        map<int,bool> mark;
        map<int,int> count;
        map<int,vector<int>> result;
        int res=0;
      
        for (int i=0;i<k;i++) preworker.insert(i);
        for (int i=0;i<arrival.size();i++) {
           
            while(!working.empty()&&working.top().first<=arrival[i]) {
            	if (working.size())cout<<"working.top()="<<working.top().first<<","<<working.top().second<<"\t";
                preworker.insert(working.top().second);
                mark[working.top().second]=0;
                working.pop();

            }
           
            if (preworker.size()) {
            	cout<<"i="<<i<<"\tarrival[i]="<<arrival[i]<<"\tload[i]="<<load[i]<<endl;
            	if (working.size())cout<<"working.top()="<<working.top().first<<","<<working.top().second<<"\t";
            	cout<<endl;
                auto it=preworker.lower_bound(i%k);
                int t=*preworker.begin();
                if (it!=preworker.end()) t=*it;
               	
                working.push({arrival[i]+load[i],t});
                mark[t]=1;
                count[t]++;
             	cout<<"t= "<<t<<"\tcount[t]="<<count[t]<<endl;
                res=max(res,count[t]);
                result[count[t]].push_back(t);
                preworker.erase(t);
                
            }


        }
       
        return result[res];
    }
int main() {
	int k=7;
	vector<int> arrival={1,3,4,5,6,11,12,13,15,19,20,21,23,25,31,32};
	vector<int> load={9,16,14,1,5,15,6,10,1,1,7,5,11,4,4,6};
	vector<int> t=busiestServers(k,arrival,load);
	for (int i=0;i<t.size();i++) cout<<t[i]<<" ";
}