long long L[1010];
L[0]=1;
for (int i=1;i<=n;i++) {
	for (int t=S;t>=a[i];t--) {
		if (L[t-a[i]]==1) L[t]=i;
	}
}