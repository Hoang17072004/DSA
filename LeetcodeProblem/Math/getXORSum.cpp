 int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int first=0;
        for (int i=0;i<arr1.size();i++) first^=arr1[i];
        int second=0;
        for (int i=0;i<arr2.size();i++) second^=arr2[i];
        return first&second;
    }
