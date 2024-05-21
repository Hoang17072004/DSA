#include<bits/stdc++.h>
using namespace std;
int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(),tasks.end());
    sort(workers.begin(),workers.end());
    int smaller[workers.size()]={0};
    int j=0;
    for (int i=0;i<workers.size();i++) {
    	
    	while(j<tasks.size()&& workers[i]>=tasks[j]) j++;
    	smaller[i]=j;
	}
	for (int i=0;i<workers.size();i++) cout<<smaller[i]<<" ";
}
int main() {
	vector<int> tasks = {3,2,1};
	vector<int> workers = {0,3,3};int  pills = 1, strength = 1;
	maxTaskAssign(tasks,workers,pills,strength);
}
