#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
     map<char,bool> check;
 	map<char,int> mark;
    for (int i=0;i<t.size();i++) {
		check[t[i]]=1;
		mark[t[i]]++;
	}
	int l=0;

	int cnt=mark.size();
	
	int res=1000000;
	int start=0,end=-1;
	cout<<"cnt="<<cnt<<endl;
	for (int r=0;r<s.size();r++) {
		if (check[s[r]]) {
			mark[s[r]]--;
			if (mark[s[r]]==0) {
				cnt--;
			}
			while(cnt==0) {
				if (res>r-l+1) {
					res=r-l+1;start=l;end=r;
				}
				if (check[s[l]]) {
					mark[s[l]]++;
					if (mark[s[l]]>0) cnt++;
				}
				l++;
			}

		} 
	} 
	return s.substr(start,end-start+1);
}
int main() {
	string s,t; cin>>s>>t;
	cout<<minWindow(s,t);
}
