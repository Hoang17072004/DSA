class Solution {
public:
    

    bool canTransform(string start, string end) {
    	string first="",second="";
        for (int i=0;i<start.size();i++) {
            if (start[i]!='X') first+=start[i];
            if (end[i]!='X') second+=end[i];
        }
        if (first!=second) return false; 
       int i=0,j=0;
       int n=start.size();
       while(i<n&&j<n) {
           while(i<n&&start[i]=='X') i++;
           while(j<n&&end[j]=='X') j++;
           if (i==n&&j==n) return true;
           if (i==n||j==n) return false;
           if (start[i]!=end[j]) return false;
           if (start[i]=='L' &&i<j) return false;
           if (start[i]=='R' &&i>j) return false;
           i++;j++;
       }
       return true;
    }
};
