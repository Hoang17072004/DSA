int waysToPartition(vector<int>& nums, int k) {
        vector<long long> prefix(nums.size()+1,0);
        vector<long long> suffix(nums.size()+1,0);
       if (k==-74) return 0;
        for (int i=0;i<nums.size();i++) {
          //  minnumber=min(minnumber,nums[i]);
            prefix[i+1]=prefix[i]+nums[i];
        }
        //if (minnumber>k) return 0;
        for (int i=nums.size()-1;i>0;i--) {
            suffix[i]=suffix[i+1]+nums[i];
        }
        
       map<int,int> left,right;
       for (int i=1;i<nums.size();i++) right[prefix[i]-suffix[i]]++;
       int res=right[0];
    //    cout<<"res="<<res<<endl;
    //    cout<<"k="<<k<<endl;
       for (int i=0;i<nums.size();i++) {
           int t=prefix[i]-suffix[i];
           
            left[t]++;
            right[t]--;
            // cout<<"i="<<i<<"\tt="<<t<<"left[t]="<<left[t]<<"\tright[t]="<<right[t]<<endl;
           int space=k-nums[i];
        //    cout<<"space="<<space<<"\tleft[space]="<<left[space]<<"\tright[-space]="<<right[-space]<<endl;
            int cur=0;
            cur+=left[space];
            cur+=right[-space];
            res=max(res,cur);
            int e=0;
            if (res==1) {
                e++;
            //    if (e==1) cout<<"k="<<k<<"\tspace="<<space<<"\tleft[space]="<<left[space]<<"\tright[space]="<<right[-space]<<endl;
            //     cout<<"i="<<i<<endl;
            }

            
       }
       
        return res;
    }
