class MajorityChecker {
public:
    unordered_map<int,vector<int>> pos;
    vector<int> st;
    vector<int> a;
    int n;
    MajorityChecker(vector<int>& arr) {
        n=arr.size();
       a.resize(n+1);
       for (int i=1;i<=n;i++) {
           pos[arr[i-1]].push_back(i);
           a[i]=arr[i-1];
       }
        st=vector<int>(n*4,-1);
        build(1,1,n);
    }
    void build(int id,int l,int r) {
        if (l==r) {
            st[id]=a[l];
            return;
        }
        int m=(l+r)/2;
        build(2*id,l,m);
        build(2*id+1,m+1,r);
        if (st[2*id]!=-1&&count(st[2*id],l,r)*2>r-l+1) {
            st[id]=st[2*id];
        } else if (st[2*id+1]!=-1&&count(st[2*id+1],l,r)>r-l+1) {
            st[id]=st[2*id]+1;
        }
    }
    pair<int,int> query(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return{-1,-1};
        if (l>=u&&r<=v) {
            if (st[id]==-1) return {-1,-1};
            int occ=count(st[id],u,v);
            if (occ*2>v-u+1) return {st[id],occ}; 
             return {-1,-1};
        }
        int m=(l+r)/2;
        auto a=query(2*id,l,m,u,v);
        if (a.first>-1) return a;
        auto b=query(2*id+1,m+1,r,u,v);
        if (b.first>-1) return b;
        return {-1,-1};
    }
    int count(int num,int l,int r) {
        auto it=pos.find(num);
        if (it==pos.end()) return 0;
        auto &a=it->second;
        auto low=lower_bound(a.begin(),a.end(),l);
        auto hight=upper_bound(a.begin(),a.end(),r);
        return hight-low;
    }
    int query(int left, int right, int threshold) {
        auto ans=query(1,1,n,left+1,right+1);
        if (ans.second>=threshold) return ans.first;
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
