struct Value{
	Value(int aa=1,int bb=1,int cc=1,int nn=1):a(aa),b(bb),num(nn){
	}
	int a;//Thời điểm bắt đầu thuê
	int b;//Thời điểm kết thúc thuê
	int c;//Tiền thuê
	int num;//Số thứ tự	
};
const int N=1e3+10;
int n,f[N],d[N];
Value m[N];
bool compare(const Value&x,const Value&y) {
	return x.a<y.a||(x.a==y.a&&x.b<y.b);	
}
int main() {
	//...
	sort(m+1,m+n+1,compare);
	//Bước quy hoạch động
	for (int i=1;i<=n;i++) {
		f[i]=m[i].c;
		for (int j=1;j<i;j++) {
			if (m[j].b<=m[i].a&&h[i]<f[j]+m[i].c){
				f[i]=f[j]+m[i].c;
				d[i]=j;
			}
		}
	}
	//... truy vết
}