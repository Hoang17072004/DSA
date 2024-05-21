#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
	map<char,int> m;
	deque<int> dq;
	int n=s.size();
	int l=0;
	int res=0;
	for (int r=0;r<n;r++) {
		m[s[r]]++;
		while(l<r&&m[s[r]]>1) {
			m[s[l]]--;
			l++;
		}
		//cout<<"l="<<l<<"\tr="<<r<<endl;
		res=max(res,r-l+1);
	}        
	return res;
}
int main() {
	string s; cin>>s;
	cout<<lengthOfLongestSubstring(s);
}
