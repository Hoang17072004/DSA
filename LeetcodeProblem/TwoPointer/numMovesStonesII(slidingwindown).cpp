vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n=stones.size();
        int hight=max(stones[n-1]-stones[1]-n+2,stones[n-2]-stones[0]-n+2);
        int i=0;
        int low=n;
        for (int j=0;j<stones.size();j++) {
            while(stones[j]-stones[i]>=n) i++;
            if (j-i+1==n-1&&stones[j]-stones[i]==n-2) low=min(low,2);
            else low=min(low,n-(j-i+1));
        }
        return {low,hight};
    }
