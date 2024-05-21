#include<bits/stdc++.h>
using namespace std;
int maxRepOpt1(string text){

 string s=text;
         int count[26]={0};
        for (int i=0;i<s.size();i++) count[s[i]-'a']++;
        int res=0;
        for (char curchar='a';curchar<='z';curchar++) {

            int i=0,cnt=0;
            int differ=0;
            for (int j=0;j<text.size();j++) {
                if (s[j]!=curchar) {
                    cnt++;differ++;
                }
                while(i<j&&cnt>1) {
                    if (s[i]!=curchar) cnt--;
                    i++;
                }
                cout<<"curchar="<<curchar<<"\ti="<<i<<"\tj"<<j<<endl;
                 if (cnt==0) res=max(res,j-i+1);
                if (cnt==1&&count[curchar-'a']-(j-i)>0)res=max(res,j-i+1);
                cout<<"res="<<res<<endl;
            }
           // if (differ==1) return s.size()-1;
        }
        
        return res;      
    }
int main() {
	string text; cin>>text;
	cout<<maxRepOpt1(text);
}
