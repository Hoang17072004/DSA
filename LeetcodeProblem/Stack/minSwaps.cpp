int minSwaps(string s) {
        int cnt=0;
        int size=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='[') size++;
            else {
                if (size==0) cnt++;
                else size--;
            }
        }
        return (cnt+1)/2;
    }
