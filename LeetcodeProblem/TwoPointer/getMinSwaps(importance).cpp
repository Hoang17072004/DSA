int getMinSwaps(string num, int k) {
        string temp=num;
        while(k--) {
            int i=num.size()-2;
            while(i>=0&&num[i]>=num[i+1]) i--;
            int j=num.size()-1;
            while(j>i&&num[j]<=num[i]) j--;
            swap(num[i],num[j]);
            int l=i+1,r=num.size()-1;
            while(l<r) {
                swap(num[l],num[r]);
                l++; r--;
            }
        }
        int cnt=0;
        int n=num.size();
        for (int i=0;i<n;i++) {
            if (num[i]!=temp[i]) {
                int j=i;
                while(j<n&&temp[j]!=num[i]) j++;
                while(j>i) {
                    cnt++;
                    swap(temp[j],temp[j-1]);
                    j--;
                }
            }
        }
        return cnt;
    }
