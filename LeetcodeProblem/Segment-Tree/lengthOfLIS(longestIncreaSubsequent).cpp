class Solution {
public:
    int n;
    vector<int> st;
    void update(int id,int l,int r,int i,int val) {
        if (i<l||i>r) return;
        if (l==r) {
            st[id]=max(st[id],val);
            return;
        }
        int m=(l+r)/2;
        update(2*id,l,m,i,val);
        update(2*id+1,m+1,r,i,val);
        st[id]=max(st[2*id],st[2*id+1]);
    }
    int query(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return 0;
        if (l>=u&&r<=v) return st[id];
        int m=(l+r)/2;
        int a=query(2*id,l,m,u,v);
        int b=query(2*id+1,m+1,r,u,v);
        return max(a,b);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        n=1e5+1;
        st.assign(4*n,0);
        for (int i: nums) {
            int lower=max(0,i-k);
            int cur=1+query(1,0,n-1,lower,i-1);
            update(1,0,n-1,i,cur);
        }
        return st[1];
    }
};
