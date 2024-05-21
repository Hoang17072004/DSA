int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size(),res=-1;
        vector<int> length(n+2,0),count(n+2,0);
        for (int i=0;i<arr.size();i++) {
            int a=arr[i];
            int left=length[a-1],right=length[a+1];
            length[a]=length[a-left]=length[a+right]=left+right+1;
            count[length[a]]++;
            count[left]--;
            count[right]--;
            if (count[m]>0) res=i+1;
        }
        return res;
    }
