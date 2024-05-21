long long L[1010];
for (int i=1;i<=n;i++) {
	for (int j=1;j<=W;j++) {
		if (A[i]<=j) {
			L[i][j]=max(L[i-1][j-A[i]]+B[i],L[i-1][j]);
		} else L[i][j]=L[i-1][j];
	}
}