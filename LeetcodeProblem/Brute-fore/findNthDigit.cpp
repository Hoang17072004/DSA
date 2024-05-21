int findNthDigit(int n) {
        int len=1,i=1;
        long range=9;
        while(n>len*range) {
            n-=len*range;
            range*=10;
            i*=10;
            len++;
        }
        i+=(n-1)/len;
        string s=to_string(i);
        return s[(n-1)%len]-'0';

    }
