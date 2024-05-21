#include<bits/stdc++.h>
#include<string>
using namespace std;
bool isValidSerialization(string preorder) {
        
        stringstream ss(preorder);
        string word;
        vector<string> track;
        stack<int> st;
        map<int,int> count;
       
        while(getline(ss,word,',')) {
            if (word.size()) track.push_back(word);
        }
        for (int i=0;i<track.size();i++) {
            
            if (isdigit(track[i][0])) {
                int num=stoi(track[i]);
              
                st.push(num);
               
            }
            else {
                count[st.top()]++;
                while(st.size()&&count[st.top()]==2) {
                    st.pop();
                    count[st.top()]++;
                }
            }
        }
        if (st.empty()) return true;
        return false;
    }
int main() {
	string preoder="9,#,93,#,9,9,#,#,#";
	cout<<isValidSerialization(preoder);
}
