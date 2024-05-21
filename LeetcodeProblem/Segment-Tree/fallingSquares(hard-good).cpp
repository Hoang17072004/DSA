const static int maxN=1e5+7;
    int st[4*maxN],lazy[4*maxN];
    void fix(int id,int l,int r) {
        if (lazy[id]==-1) return;
        st[id]=lazy[id];
        if (l!=r) {
            lazy[2*id]=lazy[2*id+1]=lazy[id];
        }
        lazy[id]=-1;
    }
    void update(int id,int l,int r,int u,int v,int val) {
        fix(id,l,r);
        if (l>v||r<u) return;
        if (l>=u&&r<=v) {
            lazy[id]=val;
            fix(id,l,r);
            return;
        }
        int m=(l+r)/2;
        update(2*id,l,m,u,v,val);
        update(2*id+1,m+1,r,u,v,val);
        st[id]=max(st[2*id],st[2*id+1]);
    }
    int get(int id,int l,int r, int u,int v) {
        fix(id,l,r);
        if (l>v||r<u) return INT_MIN;
        if (l>=u&&r<=v) return st[id];
        int m=(l+r)/2;
        int get1=get(2*id,l,m,u,v);
        int get2=get(2*id+1,m+1,r,u,v);
        return max(get1,get2);
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        memset(st,0,sizeof(st));
        memset(lazy,0,sizeof(lazy));
        set<int> s;
        unordered_map<int,int> index;
        for (auto &pos: positions) {
            s.insert(pos[0]);
            s.insert(pos[0]+pos[1]-1);
        }
        int cnt=1;
        for (auto x: s) {
            index[x]=cnt++;
        }
        int n=cnt;
        vector<int> ans;
        for (auto &pos: positions) {
            int l=index[pos[0]];
            int r=index[pos[0]+pos[1]-1];
            int pre=get(1,1,n,l,r);
            update(1,1,n,l,r,pre+pos[1]);
            int temp=get(1,1,n,1,n);
            ans.push_back(temp);
        }
        return ans;
    }
