// Prefix function
vector<int> prefix_function(string s) {
	int n=(int)s.length();
	vector<int> pi(n);
	for (int i=1;i<n;i++) {
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j]) j=pi[j-1];
		if (s[i]==s[j]) j++;
		pi[i]=j;
	}
	return pi;
}
//Find all index of t in s
vector<int> pi=prefix_function(s);
int ans=0;
int j=0;
for (int i=0;i<m;i++) {
	while(j>0&&t[i]!=s[j]) j=pi[j-1];
	if (t[i]==s[j]) j++;
	if (j==n) ans++;
}
//Count frequent of prefix lengh i in s
vector<int> ans(n,1);
for (int i=n-1;i>0;i--) if (pi[i]) ans[pi[i]-1]+=ans[i];

