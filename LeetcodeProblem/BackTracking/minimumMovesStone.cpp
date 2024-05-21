int minimumMoves(vector<vector<int>>& grid) {
        int t=0;
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) if (!grid[i][j]) t++;
        }
        if (t==0) return 0;
        int ans=INT_MAX;
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++){
                if (!grid[i][j]) {
                    for (int k=0;k<3;k++) {
                        for (int l=0;l<3;l++) {
                            int d=abs(k-i)+abs(l-j);
                            if (grid[k][l]>1) {
                                grid[k][l]--;
                                grid[i][j]++;
                                ans=min(ans,d+minimumMoves(grid));
                                grid[k][l]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
