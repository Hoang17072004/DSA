int rangeBitwiseAnd(int left, int right) {
        if (left==0) return 0;
        int move=1;
        while(left!=right) {
            left>>=1;
            right>>=1;
            move<<=1;
        }
        return left*move;
    }
