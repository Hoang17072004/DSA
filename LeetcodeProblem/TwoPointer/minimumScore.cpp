#include<iostream>
#include<vector>
using namespace std;
int minimumScore(string s, string t) {
        int j=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==t[j]) j++;
            if (j==t.size()) return 0;
        }
        vector<int> left(s.size(),0);
        j=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==t[j]) j++;
            left[i]=j;
        }
        j=t.size()-1;
        int res=INT_MAX;
        for (int i=s.size()-1;i>=0;i--) {
            if (j>=left[i]) res=min(res,j-left[i]+1);
            if (s[i]==t[j]) j--;
            res=min(res,j+1);
        }
        return res;
    }
int main() {
	
}
