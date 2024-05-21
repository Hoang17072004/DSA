class Solution {
public:
    static const int maxN=3e4+1;
    int st[4*maxN]={0};
    int n;
    int a[maxN]={0};
    void update(int id,int l,int r,int i) {
        if (i<l||i>r) return;
        if (l==r) {
            st[id]++;
            return;
        }
        int m=(l+r)/2;
        update(2*id,l,m,i);
        update(2*id+1,m+1,r,i);
        st[id]=st[2*id]+st[2*id+1];
    }
    int get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return 0;
        if (l>=u&&r<=v) return st[id];
        int m=(l+r)/2;
        return get(2*id,l,m,u,v)+get(2*id+1,m+1,r,u,v);
    }
    string minInteger(string num, int k) {
        n=num.size();
        for (int i=1;i<=n;i++) a[i]=num[i-1]-'0';
        vector<deque<int>> mark(10);
        for (int i=1;i<=n;i++) {
            mark[a[i]].push_back(i);
        }
        string ans="";
        vector<bool> check(n+1,0);
        for (int i=1;i<=n;i++) {
            for (int c=0;c<10;c++) {
                if (mark[c].empty()) continue;
                int idx=mark[c].front();
                int pre=get(1,1,n,1,idx );
                int swap=idx-pre-1;
                if (k>=swap) {
                    ans+=char(c+'0');
                    mark[c].pop_front();
                    check[idx]=1;
                    k-=swap;
                    update(1,1,n,idx);
                    break;
                }
                
            }
        }
        //for (int i=1;i<=n;i++) if (!check[i]) ans+=char(a[i]+'0');
        return ans;
    }
};
