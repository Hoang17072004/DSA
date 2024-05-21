int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int res=0;
        for (int i=0;i<houses.size();i++) {
            int l=0,r=heaters.size()-1;
            while(l<=r) {
                int m=(l+r)/2;
                if (heaters[m]==houses[i]) {
                    
                    break;
                } else if (houses[i]<heaters[m]) r=m-1; else l=m+1;
            }
            if (l>r) {
                swap(l,r);
                int left=(l<0)?INT_MAX:houses[i]-heaters[l];
                int right=(r==heaters.size())?INT_MAX: heaters[r]-houses[i];
                res=max(res,min(left,right));
            }
        }
        return res;
    }
