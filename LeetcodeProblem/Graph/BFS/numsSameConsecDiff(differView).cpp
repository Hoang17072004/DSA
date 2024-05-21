class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for (int i=1;i<10;i++) q.push(i);
        for (int level=1;level<n;level++) {
            int length=q.size();
            while(length--) {
                int num=q.front();
                q.pop();
                int digit=num%10;
                vector<int> a;
                if (digit+k<10) a.push_back(digit+k);
                if (k>0&&digit-k>=0) a.push_back(digit-k);
                for (int next: a) q.push(num*10+next);
            }
        }
        vector<int> res;
        while(q.size()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
