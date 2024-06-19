#include<iostream>
#include<unordered_set>
using namespace std;
unordered_set<int> solve(int a) {
	unordered_set<int> candidates;
	for (int i=1;i*i<=a;i++) {
		if (a%i==0) {
			if (i%2==0) candidates.insert(i);
			if ((a/i)%2==0) candidates.insert(a/i);
		}
	}
	
	unordered_set<int> answer;
	for (int i: candidates) answer.insert(1+i/2);
	return answer;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,pos;
		cin>>n>>pos;
		unordered_set<int> candidates=solve(n-pos);
		for (int i: solve(n+pos-2)) candidates.insert(i);
		int answer=0;
		for (int i:candidates) {
			if (i>=pos) answer++;
		}	
		cout<<answer<<endl;
	}
	
}