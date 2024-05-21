int makeTheIntegerZero(long long num1, long long num2) {
        for (int k=0;k<=60;k++) {
            int target=num1-k*num2;
            if (target>=0&&__builtin_popcount(target)<=k&&k<=target) return k;
        }
        return -1;
    }
