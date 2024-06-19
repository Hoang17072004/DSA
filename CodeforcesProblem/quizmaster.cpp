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

void dfs(vector<pair<int,int>>&nums,int k,int val,int m,int idx,vector<vector<int>> &contain,vector<vector<int>>&memo) {
	if (val>m) return;
	if (k==nums.size()) {
		contain[val].push_back(idx);
		memo[idx].push_back(val);
		return;
	}
	int s=1;
	for (int i=0;i<=nums[k].second;i++) dfs(nums,k+1,val*s,m,idx,contain,memo),s*=nums[k].first;
}
void solve() {
	int n,m; cin>>n>>m;
	int a[n];
	vector<vector<int>> contain(m+1);
	vector<vector<int>> memo(n);
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++) {
		int x=a[i];
		map<int,int> count;
		while (x != 1) {
//	        res.push_back(minPrime[x]);
	        count[min_prime[x]]++;
	        x /= min_prime[x];
    	}
    	vector<pair<int,int>> nums;
    	for (auto &p: count) nums.push_back(p);
    	dfs(nums,0,1,m,i,contain,memo);
	}
	set<int> s;
//	for (int i=0;i<n;i++) {
//		for (int x: memo[i]) cout<<x<<" "; cout<<endl;
//	}
	int res=INT_MAX;
	for (int i=0,j=0;i<n;i++) {
		while(j<n&&s.size()<m) {
			for (int x: memo[j]) s.insert(x);
			j++;
		}
//		cout<<"size="<<s.size()<<endl;
		if (s.size()<m) break;
		res=min(res,a[j-1]-a[i]);
		for (int x: memo[i]) {
			auto it=upper_bound(contain[x].begin(),contain[x].end(),i);
			if (it==contain[x].end()||*it>=j) s.erase(x);
		}
	}
	if (res==INT_MAX) cout<<-1<<endl; else
	cout<<res<<endl;
}
int main() {
	sieve(maxn);
	int t; cin>>t;
	while(t--) solve();
}