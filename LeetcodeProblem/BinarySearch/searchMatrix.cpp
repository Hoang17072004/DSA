bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int row=0,col=n-1;
        while(col>=0&&row<m) {
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) col--; else row++;
        }
        return false;
    }
