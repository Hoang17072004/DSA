vector<int> z_function(string s) {
	int n=s.length();
	vector<int> z(n);
	for (int i=1,l=0,r=0;i<n;i++) {
		if (i<=r) z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
		if (i+z[i]-1>r) {
			l=i;
			r=i+z[i]-1;
		}
	}
	return z;
}
vector<int> string_matching(string s,string t) {
	string p=t+'#'+s;
	int m=t.length();
	int n=s.length();
	vector<int> z=z_function(p);
	vector<int> res;
	for (int i=m+1;i<=m+n;i++) {
		if (z[i]==m) res.push_back(i-m-1);
	}
	return res;
}
