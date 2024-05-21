vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol=0,endCol=mat[0].size()-1;
        while(startCol<=endCol) {
            int midCol=startCol+(endCol-startCol)/2;
            int maxRow=0;
            for (int i=0;i<mat.size();i++) if (mat[maxRow][midCol]<mat[i][midCol]) maxRow=i;
            bool isLeftBig=(midCol-1>=startCol&&mat[maxRow][midCol-1]>mat[maxRow][midCol]); 
            bool isRightBig=(midCol+1<=endCol&&mat[maxRow][midCol+1]>mat[maxRow][midCol]);
            if (!isLeftBig&&!isRightBig) return vector<int>{maxRow,midCol};
            if (isRightBig) startCol=midCol+1; else endCol=midCol-1;
        }
        return vector<int>{-1,-1};
    }
