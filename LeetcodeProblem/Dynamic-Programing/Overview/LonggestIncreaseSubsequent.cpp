//Khởi tạo dãy a các phần tử ban đầu bằng 0
for (int i=0;i<n;i++) {
	for (int j=0;j<i;j++) {
		if (a[j]<=a[i]) s[i]=max(s[i],s[j]+1);
	}
}