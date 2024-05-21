#include<bits/stdc++.h>
using namespace std;
int longestSubstring(string s, int k) {
    int charfre[26]={0};int uniquechar=0;
    for (int i=0;i<s.size();i++) {
		charfre[s[i]-'a']++;
		if (charfre[s[i]-'a']==k) uniquechar++;
	}
	int res=0;
	
	for (int curunique=1;curunique<=uniquechar;curunique++) {

		int start=0,end;
		memset(charfre,0,sizeof(charfre));
		int uniquecur=0,unicurlargerk=0;
		for (end=0;end<s.size();end++) {
			charfre[s[end]-'a']++;
			if (charfre[s[end]-'a']==1)  uniquecur++;
			if (charfre[s[end]-'a']==k) unicurlargerk++;
			while(start<end&& uniquecur>curunique) {
				charfre[s[start]-'a']--;
				if (charfre[s[start]-'a']==0) uniquecur--;
				if (charfre[s[start]-'a']==k-1) unicurlargerk--;
				start++;
			}
			
			if (uniquecur==curunique&&unicurlargerk==curunique) {

				res=max(res,end-start+1);
			}
		}
	}
    
   return res;
}
int main() {
	string s; int k; cin>>s>>k;
	cout<<longestSubstring(s,k);
}
