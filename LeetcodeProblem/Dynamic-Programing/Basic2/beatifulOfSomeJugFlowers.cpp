vector<int> P(k+1),L(k+1);
for (int i=1;i<=n;i++) {
	for (int j=1;j<=i;j++) {
		L[j]=max(P[j-1]+v[i][v],P[j]);
	}
	P=L;
}
cout<<L[k];