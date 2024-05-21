void flip(vector<int> &arr,int r) {
        int left=0,right=r;
        while(left<right) {
            swap(arr[left],arr[right]);
            left++; right--;
        }
    }
    int find(vector<int> &arr,int x) {
        for (int i=0;i<arr.size();i++) if (arr[i]==x) return i;
        return 0;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int n=arr.size();
       vector<int> ans;
        for (int value=n;value>0;value--) {
            int idx=find(arr,value);
            if (idx==value-1) continue;
            if (idx>0) {
                ans.push_back(idx+1);
                flip(arr,idx);
            }
            ans.push_back(value);
            flip(arr,value-1);
        }
        return ans;
    }
