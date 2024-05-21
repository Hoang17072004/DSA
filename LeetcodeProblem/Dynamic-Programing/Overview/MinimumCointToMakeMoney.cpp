//Gán Min[i] bằng dương vô cùng với mọi i
Min[0]=0;
for (int i=1;i<=S;i++) {
	for (int j=0;j<N;j++) {
		if (V[j]<=i&&Min[i-V[j]]+1<Min[i]) Min[i]=Min[i-Vj]+1;
	}
}
return Min[S];