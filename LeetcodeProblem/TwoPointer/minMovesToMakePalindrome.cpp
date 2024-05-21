int find(string s,int l,int r) {
        for (int i=r-1;i>l;i--) if (s[i]==s[l]) return i;
        return l;
    }
    int minMovesToMakePalindrome(string s) {
        int step=0;
        int n=s.size();
        int l=0,r=n-1;
        string temp=s;
        while(l<r) {
            if (temp[l]==temp[r]) {
                l++; r--;
            } else {
                int k=find(temp,l,r);
                if (k==l) {
                    swap(temp[l],temp[l+1]);
                     step++;
                } else {
                    while(k<r) {
                        swap(temp[k],temp[k+1]);
                        k++;
                        step++;
                    }
                    l++;r--;
                }
            }
        }
        return step;
    }
