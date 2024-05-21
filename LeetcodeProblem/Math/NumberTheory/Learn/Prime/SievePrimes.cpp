const int maxn=1e6+5;
bool is_prime[maxn];//mảng bool khởi tạo với các giá trị false
void sieve(int n) {
	//Đánh dấu các số từ 2 đến n đều là số nguyên tố
	for (int i=2;i<=n;i++) is_prime[i]=true;
	for (int i=2;i<=n;i++) {
		if (is_prime[i]) {
			for (int j=i*2;j<=n;j+=i) 
			//Bỏ đánh dấu tất cả các số không phải số nguyên tố
			is_prime[j]=false;
		}
	}
}
//Cải tiến 2
const int maxn=1e6+5;
bool is_prime[maxn];
void Eratosthenes(int n) {
	for (int i=2;i<=n;i++) is_prime[i]=true;
	for (int i=2;i*i<=n;i++) {
		if (is_prime[i]) {
			//j sẽ bắt đầu chạy từ i*i
			for (int j=i*i;j<=n;j+=i) is_prime[j]=false;
		}
	}
}
//Phân tích ra thừa số nguyên tố với i nhỏ hơn 10 mũ 6
const int maxn=1e6+5;
int min_prime[maxn];
void sieve(int n) {
	for (int i=2;i*i<=n;i++) {
		if (min_prime[i]==0) {//nếu i là số nguyên tố
			for (int j=i*i;j<=n;j+=i) {
				if (min_prime[j]==0) {
					min_prime[j]=i;
				}
			}
			
		}
	}
	for (int i=2;i<=n;i++) {
		if (min_prime[i]==0) {
			min_prime[i]=i;
		}
	}
}
//Bây giờ ta phân tích 1 số ra thừa số nguyên tố
vector<int> factorize(int n) {
	vector<int> res;
	while(n!=1) {
		res.push_back(minPrime[n]);
		n/=minPrime[n];
	}
	return res;
}
//Đối với số lớn
vector<long long> factiorize(long long n) {
	vector<long long> res;
	for (long long i=2;i*i<=n;i++) {
		while(n%i==0) {
			res.push_back(i);
			n/=i;
		}
	}
	if (n>1) res.push_back(n);
	return res;
}
//Cải tiến thuật toán chỉ cần tìm số nguyên tố trong đoạn [2;sqrt(n)]
vector<int> primes;//chứa các số nguyên tố từ đoạn [2,sqrt(n)]
vector<long long> factorize(long long n) {
	vector<long long> res;
	for (int p: primes) {
		if (1LL*p*p>n) break;
		while(n%p==0) {
			res.push_back(p);
			n/=p;
		}
	}
	if (n>1) res.push_back(n);
	return res;
}
//Tìm số nguyên tố trong đoạn [L;R]
vector<bool> sieve(long long L,long long R) {
	long long sqrtR=sqrt(R);
	vector<bool> mark(sqrtR+1,false);
	vector<long long> primes;
	//sinh ra các số nguyên tố <=sqrt(R)
	for (long long i=2;i<=sqrtR;i++) {
		if (!mark[i]) {
			primes.push_back(i);
			for (long long j=i*i;j<=sqrtR;j+=i) mark[j]=true;
		}
	}
	vector<bool> isPrime(R-L+1,true);
	for (long long i: primes)
		for (long long j=max(i*i,(L+i-1)/i*i);j<=R;j+=i) isPrime[j-L]=false;
	if (L==1) isPrime[0]=false;
	return isPrime;
}
//Cải tiến: Ta cũng không cần phải sinh trước các số nguyên tố trong đoạn [1;sqrt(R)]
vector<bool> is_prime;
void sieve(int L,int R) {
	is_prime.assign(R-L+1,true);
	//x là số nguyên tố khi và chỉ khi is_prime[x-l]==true
	for (long long i=2;i*i<=R;i++) {
	//Lưu ý: (L+i-1)/i*i là bội nhỏ nhất của i mà >=L
		for(long long j=max(i*i,(L+i-1)/i*i);j<=R;j+=i) {
			is_prime[j-L]=false;
		}
	}
	if (1>=L) {//Xét riêng trường hợp số 1
		is_prime[1-L]=false;
	}
	for (long long x=L;x<=R;x++) {
		if (is_prime[x-L]) {
			// x là số nguyên tố
		}
	}
}
//Sàng nguyên tố tuyến tính
// Duyệt qua các số nguyên tố nhỏ hơn n
vector<int> min_prime,primes;
void linear_sieve(int n) {
	min_prime.assign(n+1,0);
	for (int i=2;i<=n;i++) {
		if (min_prime[i]==0) {
			min_prime[i]=i;
			primes.push_back(i);
		}
		for (int j=0;i*primes[i]<=n;j++) {
			min_prime[i*primes[j]]=primes[j];
			if (primes[j]==min_prime[i]) break;
		}
	}
}
//Hàm phân đoạn
vector<int> primes;
void segmented_sieve(int n) {
	const int S=10000;
	int nsqrt=sqrt(n);
	vector<char> is_prime(nsqrt+2,true);
	for (int i=2;i<=nsqrt;i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j=i*i;j<=nsqrt;j+=i) is_prime[j]=false;
		}
	}
	int result=0;
	vector<char> block(S);
	for (int k=0;k*S<=n;k++) {
		fill(block.begin(),block.end(),true);
		int start=k*S;
		for (int p: primes) {
			//start_idx*p là bội nhỏ nhất của p mà start_idx*p>=start
			int start_idx=(start+p-1)/p;
			int j=max(start_idx,p)*p-start;
			for (;j<S;j+=p) block[j]=false;
		}
		if (k==0) block[0]=block[1]=false;
		for (int i=0;i<S&&start+i<=n;i++) if (block[i]) resul++;
	}
	cout<<result<<"\n";
}