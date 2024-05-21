class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.size();
        int zero=0,second=0;
       for (int i=0;i<n;i++) {
           if (s[i]=='0') zero ++;
           else if (zero) second=max(second+1,zero);
           }
       return second;
    }
};
