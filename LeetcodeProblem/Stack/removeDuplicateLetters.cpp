string removeDuplicateLetters(string s) {
        int lastIndex[26]={0};
        for (int i=0;i<s.size();i++) lastIndex[s[i]-'a']=i;
        bool check[26]={0};
        stack<char> st;
        for (int i=0;i<s.size();i++) {
            if (check[s[i]-'a']) continue;
            while(st.size()&&st.top()>s[i]&&i<lastIndex[st.top()-'a']) {
                check[st.top()-'a']=0;
                st.pop();

            } 
            st.push(s[i]);
            check[s[i]-'a']=1;
        }
        string ans="";
        while(st.size()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
