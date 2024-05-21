class Solution {
public:
    static const int NUMBEROFNODES=1000000;
    int LOG=31;
    struct Node{
        int child[2];
        int cnt;
        int exist;
    }nodes[NUMBEROFNODES];
    int cur;
    Solution():cur(0) {
        memset(nodes[0].child,-1,sizeof(nodes[0].child));
        nodes[0].cnt=nodes[0].exist=0;
    }
    int new_node() {
        cur++;
        memset(nodes[cur].child,-1,sizeof(nodes[cur].child));
        nodes[cur].cnt=nodes[cur].exist=0;
        return cur;
    }
    void add_num(int num) {
        int pos=0;
        for (int i=LOG;i>=0;i--) {
            int c=(num>>i)&1;
            if (nodes[pos].child[c]==-1) nodes[pos].child[c]=new_node();
            pos=nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[cur].exist++;
    }

    int count(int num,int k) {
        int cnt=0;
        int pos=0;
        for (int i=LOG;i>=0;i--) {
            int a=(num>>i)&1;
            int b=(k>>i)&1;
            if (b) {
                if (nodes[pos].child[a]!=-1) {
                    int t=nodes[pos].child[a];
                    cnt+=nodes[t].cnt;
                }
                if (nodes[pos].child[a^1]!=-1) {
                    pos=nodes[pos].child[a^1];
                } else return cnt;
            } else {
                if (nodes[pos].child[a]!=-1) {
                    pos=nodes[pos].child[a];
                } else return cnt;
            }

        }
       
        return cnt;
    }
    int countPairs(vector<int>& nums, int low, int high) {

        int res=0;
        for (int x: nums) {
            res+=count(x,high+1)-count(x,low);
            add_num(x);
        }
        return res;
    }
};
