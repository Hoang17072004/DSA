bool canBeValid(string s, string locked) {
        int n=s.size();
        if (n%2==1) return false;
        int balance=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='('||locked[i]=='0') balance++;
            else balance--;
            if (balance<0) return false;
        }
        balance=0;
        for (int i=n-1;i>=0;i--){
            if (s[i]==')'||locked[i]=='0') balance++;
            else balance--;
            if (balance<0) return false;
        }
        return true;
    }
