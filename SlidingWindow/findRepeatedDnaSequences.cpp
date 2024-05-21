#include<bits/stdc++.h>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        string temp;
        vector<string> v;
        int n=s.size();
        cout<<"n-10="<<n-10<<endl;
        cout<<"s.size="<<s.size()<<endl;
        for (int i=0;i<=n-10;i++) {
        	cout<<"haha\n";
            temp=s.substr(i,10);
            if (m[temp]==1) v.push_back(temp);
            m[temp]++;

        } 
        return v;
}
int main() {
	string s="A";
	vector<string> v=findRepeatedDnaSequences(s);
	for (int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
