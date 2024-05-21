bool validUtf8(vector<int>& data) {
        int cnt=0;
        int mask1=1<<7,mask2=1<<6;
        for (int i=0;i<data.size();i++) {
            if (cnt==0) {
                int mask=1<<7;
                while(mask&data[i]) {
                    mask>>=1;
                    cnt++;
                }
                if (cnt==0) continue;
                if (cnt>4||cnt==1) return false;

            } else {
                if (!(data[i]&mask1&&(data[i]&mask2)==0)) return false;
            }
            cnt--;
        }
        return cnt==0;
    }
