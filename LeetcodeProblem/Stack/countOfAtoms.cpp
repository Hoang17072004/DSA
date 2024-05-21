string countOfAtoms(string formula) {
        stack<pair<string,int>> st;
        map<string,int> m;
        for (int i=0;i<formula.size();i++) {
            if (isupper(formula[i])) {
                string temp="";
                temp+=formula[i];
                int j=i+1;
                while(j<formula.size()&&islower(formula[j])) {
                    temp+=formula[j];
                    j++;
                }
                int num=0;
                while(j<formula.size()&&isdigit(formula[j])) {
                    num=num*10+formula[j]-'0';
                    j++;
                }
                if (num) st.push({temp,num});
                else st.push({temp,1});
                i=j-1;

            } else if (formula[i]=='(') st.push({"0",0});
            else if (formula[i]==')') {
                int j=i+1;
                int num=0;
                while(j<formula.size()&&isdigit(formula[j])) {
                    num=num*10+formula[j]-'0';
                    j++;
                }
                int pre=num?num:1;
                stack<pair<string,int>> temp;
                while(st.top().first!="0") {
                    temp.push(st.top());
                    st.pop();
                }
                st.pop();
                while(temp.size()) {
                    st.push({temp.top().first,temp.top().second*pre});
                    temp.pop();
                }
                i=j-1;
            }
        }
        while(st.size()) {
            m[st.top().first]+=st.top().second;
            st.pop();
        }
        string res="";
        for (auto x: m) {
            if (x.second>1) res+=x.first+to_string(x.second);
            else res+=x.first;
        }
        return res;
    }
