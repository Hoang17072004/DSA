int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int lmax=INT_MIN,rmax=INT_MIN;
        int s=0;
        while(l<=r) {
            if (height[l]>=lmax) lmax=height[l++];
            else if (height[r]>=rmax) rmax=height[r--];
            else if (lmax<rmax) {
                
                s+=lmax-height[l];
                l++;
            }  else {
                cout<<"l="<<l<<"\tr="<<r<<"\tChon r"<<endl;
                s+=rmax-height[r];
                r--;
            }

        }
        return s;
    }
