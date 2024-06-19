#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5; //10^6 + 5
int min_prime[maxn];
void sieve(int n){
    for (int i = 2; i * i <= n; ++i) {
        if (min_prime[i] == 0) { //nếu i là số nguyên tố
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
}
void solve() {
	int n; cin>>n;
	int a[n];
	map<int,set<int>> g;
	map<int,int> index;
	for (int i=0;i<n;i++) {
		set<int> s;
		cin>>a[i];
		index[a[i]]=i;
		int x=a[i];
		while(x!=1) {
			s.insert(min_prime[x]);
			x/=min_prime[x];
//			cout<<"x="<<x<<endl;
		}
		for (int y: s) {
			if (y==a[i]) continue;
			g[y].insert(a[i]);
			g[a[i]].insert(y);
		}
	}
//	cout<<"on\n";
	int c1,c2; cin>>c1>>c2;c1--,c2--;
	int s=a[c1],ta=a[c2];
	set<int> visit;
//	cout<<"s="<<s<<",ta="<<ta<<endl;
	if (c1==c2) {
		cout<<1<<endl;
		cout<<c1+1<<endl;
		return;
	}
	if (s==1||ta==1) {
		cout<<-1<<endl;
		return;
	}
	if (s==ta) {
		cout<<2<<endl<<c1+1<<" "<<c2+1<<endl;
		return;
	}
	if (__gcd(s,ta)>1) {
		cout<<2<<endl;
		cout<<c1+1<<" "<<c2+1<<endl;
		return;
	}
	queue<pair<int,int>> q;
	visit.insert(s);
	map<int,int> mark;
	q.push({s,0});
	while(q.size()) {
		int u=q.front().first,d=q.front().second;
		q.pop();
		
		for (int v:g[u])  {
			if (v==ta) {
//				cout<<(int)ceil((d+1)/2.0)+1<<endl;
				vector<int> path;
				int t=u;
				while(t!=s) {
					path.push_back(t);
					t=mark[t];
				}
				vector<int> res;
				reverse(path.begin(),path.end());
//				res.push_back(s);
			
				for (int x: path) if (min_prime[x]!=x) res.push_back(x);
//				res.push_back(ta);
				cout<<2+res.size()<<endl;
				cout<<c1+1<<" ";
				for (int x: res) cout<<index[x]+1<<" ";
				cout<<c2+1;
				cout<<endl;
				return;
			}
			if (visit.find(v)==visit.end()) {
				q.push({v,d+1});
				visit.insert(v);
				mark[v]=u;
			}
		}
	}
	cout<<-1<<endl;
}
int main() {
	sieve(maxn);
//	int t; cin>>t;
//	while(t--) 
	solve();
}