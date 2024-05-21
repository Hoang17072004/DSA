long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        priority_queue<int,vector<int>,greater<int>> minheap;
        priority_queue<int> maxheap;
        vector<long long> minsum(nums.size(),0);
        vector<long long> maxsum(nums.size(),0);
        long long s=0;
        for (int i=0;i<nums.size();i++) {
            if (maxheap.size()<n) {
                s+=nums[i];
                maxheap.push(nums[i]); 
                if (maxheap.size()==n) minsum[i]=s;
            }
            else {
                int top=maxheap.top();
                s-=top;
                maxheap.pop();
                int smaller=min(top,nums[i]);
                s+=smaller;
                minsum[i]=s;
                maxheap.push(smaller);
            }
        }
        s=0;
        
        for (int i=nums.size()-1;i>=0;i--) {
            if (minheap.size()<n) {
                s+=nums[i];
                minheap.push(nums[i]);
                if (minheap.size()==n) maxsum[i]=s;

            } else {
                int top=minheap.top();
                s-=top;
                minheap.pop();
                int larger=max(top,nums[i]);
                s+=larger;
                maxsum[i]=s;
                minheap.push(larger);
            }
        }
        long long res=10000000000000;
        
        for (int i=n-1;i<=2*n-1;i++) if (minsum[i]&&maxsum[i]) res=min(res,minsum[i]-maxsum[i+1]);
        return res;
    }
