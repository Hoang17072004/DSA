class Solution {
public:
    struct node{
        int nums,left,right;
        char lc,rc;
        static node merge(node &a,node &b,int m) {
            node res;
            res.lc=a.lc; res.rc=b.rc;
            res.left=a.left; res.right=b.right;
            if (a.lc==b.lc) {
                if (a.left==m) res.left=b.left;
            }
            if (a.rc==b.rc) {
                if (b.right==m+1) res.right=a.right;
            }
            res.nums=max(a.nums,b.nums);
            if (a.rc==b.lc) res.nums=max(res.nums,b.left-a.right+1);
            return res;
        }
    };
    string str="";
    static const int maxN=1e5+1;
    int n;
    node st[4*maxN];
    void build(int id,int l,int r) {
        if (l==r){
            st[id].lc=st[id].rc=str[l];
            st[id].nums=1;
            st[id].left=st[id].right=l;
            return;
        }
        int m=(l+r)/2;
        build(2*id,l,m);
        build(2*id+1,m+1,r);
        for (int i=0;i<26;i++) {
            st[id]=node::merge(st[2*id],st[2*id+1],m);
        }
    }
    void update(int id,int l,int r,int i,char ch) {
        if (i<l||i>r) return;
        if (l==r) {
            st[id].lc=st[id].rc=ch;
            return;
        }
        int m=(l+r)/2;
        update(2*id,l,m,i,ch);
        update(2*id+1,m+1,r,i,ch);
        st[id]=node::merge(st[2*id],st[2*id+1],m);
    }
    node get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return node();
        if (l>=u&&r<=v) return st[id];
        int m=(l+r)/2;
        node g1=get(2*id,l,m,u,v);
        node g2=get(2*id+1,m+1,r,u,v);
        node t= node::merge(g1,g2,m);
        return t;
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str=" "+s;
      
         n=s.size();
         cout<<"n="<<n<<endl;
        build(1,1,n);
        vector<int> res;
        for (int i=0;i<queryCharacters.size();i++) {
            update(1,1,n,queryIndices[i]+1,queryCharacters[i]);
            node val=get(1,1,n,1,n);
            // s[queryIndices[i]]=queryCharacters[i];
            res.push_back(val.nums);
        }
        return res;
    }
};
