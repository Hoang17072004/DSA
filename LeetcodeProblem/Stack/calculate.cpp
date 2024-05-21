int calculate(string s) {
        
        stack<pair<int,int>> num;
        int sign=1;
        long long a=0;
        for (int i=0;i<s.size();i++) {
            if (isdigit(s[i])) {
                long long sum=0;
                while(i<s.size()&&isdigit(s[i])) {
                    sum=sum*10+s[i]-'0';
                    i++;
                }
                a+=sign*sum;
                sign=1;
                i--;
            } else if (s[i]=='(') {
                num.push({a,sign});
                a=0;
                sign=1;
            }
            else if (s[i]==')') {
                a=num.top().first+a*num.top().second;
                num.pop();
                
            } else if (s[i]=='-') sign*=-1;
        }
        return a;
    }
