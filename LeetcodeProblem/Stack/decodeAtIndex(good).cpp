string decodeAtIndex(string s, int k) {
        long long totalsize=0;
        for (int i=0;i<s.size();i++) {
            if (isalpha(s[i]))  totalsize++;
            else if(isdigit(s[i])) {
                totalsize*=(s[i]-'0');
            }
        }
        for (int i=s.size()-1;i>=0;i-- ) {
            if (isdigit(s[i])) {
                totalsize/=(s[i]-'0');
                k%=totalsize;
            } else {
                if (k==0||k==totalsize) return string(1,s[i]);
                totalsize--;
            }
        }
        return "";
       
    }
