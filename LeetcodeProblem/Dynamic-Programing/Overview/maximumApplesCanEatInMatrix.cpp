//Kh?i t?o array a ban d?u b?ng 0
for (int i=0;i<n;i++) {
	for (int j=0;j<m;j++) {
		s[i][j]=a[i][j]+max(s[i][j-1],if j>0;s[i-1][j],if i>0,0);
	}
}
return s[n-1][m-1];