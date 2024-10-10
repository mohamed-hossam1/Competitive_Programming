*----------------------------------------------------------------------*
k-th_is_not_divisible_by_n(int n,int k) return k + (k - 1) / (n - 1);   // n = 3 k = 7 --numbers not divisible by 3 1,2,4,5,7,8,*10*,11,13…
*----------------------------------------------------------------------*
int add(int x,int y,int mid) {return(x % mod + y % mod) % mod;}
int mul(int x,int y,int mid) {return(x % mod * y % mod) % mod;}
int sub(int x,int y,int mid) {return(((x % mod - y % mod) % mod) + mod) % mod;}
int div(int x,int y,int mid) {return(x % mod * powermod(y,mod-2,mod) % mod) % mod;}
int mod_negative(int x,int m) {return(x%m)+m%m;}
*----------------------------------------------------------------------*
vector<int> Divisors(int n){
    vector<int> v;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){ v.push_back(i); if(i*i!=n) v.push_back(n/i);}
    }
    return v;
}
*----------------------------------------------------------------------*
vector<int> SumDivisorsForAllNumbers(){
    vector<int>divsors(1e6+10,0);
    for (int i = 1; i <= (int)1e6; i++) 
	for (int k = i; k <= (int)1e6; k += i) divsors[k]++;
    return divsors;
}
*----------------------------------------------------------------------*
vector<int> primeFactors(int n) {
    vector<int> v;
    while (n % 2 == 0) {
        v.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 2) v.push_back(n);
    return v;
}
*----------------------------------------------------------------------*
vector<int> primeCount(int maxN) {
    vector<int> count(maxN + 1, 0);
    vector<bool> prime(maxN + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p <= maxN; ++p) {
        if (prime[p]) {
            for (int i = p; i <= maxN; i += p) {
                prime[i] = false;
                count[i] += 1;
            }
        }
    }
    for (int i = 1; i <= maxN; ++i) {
        count[i] += count[i - 1];
    }
    return count;
}

*----------------------------------------------------------------------*
int gcd(int a,int b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(a%b,b);
}
*----------------------------------------------------------------------*
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
*----------------------------------------------------------------------*
bool isprime(int n){
    if(n<=1)return 0;
    if(n!=2&&n%2==0) return 0;
    for (int i = 3; i*i <= n; i+=2)
        if(n%i==0)return 0;
    return 1;
}
*----------------------------------------------------------------------*
bool is_prime(int n) {// 1246193590755167
    bool all_ones = true;
    int m = (n - 1) / 2;
    for (int test_index = 0; test_index < 50; ++test_index) {
        int a = 1 + rand() % (n - 1);
        int a_to_the_m = 1;
        int base = a;
        int exp = m;
        int mod = n;
        while (exp > 0) {
            if (exp % 2 == 1) {
                a_to_the_m = (a_to_the_m * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        if (a_to_the_m != 1 && a_to_the_m != n - 1) {
            return false;
        }
        if (a_to_the_m == n - 1) {
            all_ones = false;
        }
    }
    return !all_ones;
}
*----------------------------------------------------------------------*
vector<bool> sieve(int n){
    vector<bool> prime(n,1);
    prime[0]=prime[1]=0;
    for (int i = 2; i*i < n; i++)
        if(prime[i])
            for (int j = i*i; j < n; j+=i)
                prime[j]=0;
    return prime;
}
*----------------------------------------------------------------------*
vector<bool> linearSieve(int N)//o(n)
{
    vector<bool>isPrime(N,1);vector<int>primes;
    isPrime[0]=isPrime[1]=0;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i]) primes.push_back(i);
        for(auto it:primes)
        {
            if(i*it>=N) break;
            isPrime[i*it]=0;
            if(i%it==0) break;
        }
    }
    return isPrime;
}
*----------------------------------------------------------------------*
vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
*----------------------------------------------------------------------*
int pow(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)      
        return pow(x*x,n/2);
    else                       
        return x*pow(x*x,(n-1)/2);
}
*----------------------------------------------------------------------*
int powmod(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return powmod((x%M*x%M)%M,n/2,M);
    else                             //n is odd
        return (x*powmod((x%M*x%M)%M,(n-1)/2,M))%M;

}
*----------------------------------------------------------------------*
int sumPows(int a, int k) { // Return a^1+a^2+.....a^k	in O(k)
	if (k == 0)
		return 0;

	if (k % 2 == 1)
		return a * (1 + sumPows(a, k - 1));

	int half = sumPows(a, k / 2);
	return half * (1 + half - sumPows(a, k / 2 -1) );
}
*----------------------------------------------------------------------*
int phi(int n) { //sqrt(n)
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
*----------------------------------------------------------------------*
void phi_1_to_n(int n) { //nlog(log(n))
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;
    for (int i = 2; i <= n; i++) 
        if (phi[i] == i) 
            for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
}
*----------------------------------------------------------------------*
math behind enjoy :)
from bezout a*x+b*y=gcd(a,b)
from euclidean gcd(a,b)=gcd(b,a%b)
b*x1+a&b*y1=gcd(a,b)      a%b = a-(a/b)*b
b*x1+(a-(a/b)*b)*y1=gcd(a,b) 
a*y1+b(x1-(a/b)*y1)=gcd(a,b)
x --> y1
y --> x1-y1*(a/b);

int x, y;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
*----------------------------------------------------------------------*
int modInverse(int a, int m) // m is prime  
{
    if (gcd(a, m) != 1)
        return -1;
 
    else {
	return powermod(a, m - 2, m);
    }
}
*----------------------------------------------------------------------*
int modInverseByextended_euclidean(int A, int M)   // A,M coprime
{
    extended_euclidean(A,M);
    return (x%M+M)%M;   
}
*----------------------------------------------------------------------*
bool solveDiophantine(int a, int b, int c) {
    int gcd = extendedEuclid(abs(a), abs(b));
    if (c % gcd != 0) {
        return false; 
    }

    x *= c / gcd;
    y *= c / gcd;

    if (a < 0) x = -x;
    if (b < 0) y = -y;
    cout << "Particular solution: x = " << x << ", y = " << y << "\n";
    cout << "General solution: x = " << x << " + k*" << b / gcd << ", y = " << y << " - k*" << a / gcd << "\n";
    return true; 
}
*----------------------------------------------------------------------*
pair<int, int> Fibonacci (int n) { return fn,fn+1
    if (n == 0)
        return {0, 1};

    auto p = Fibonacci(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
*----------------------------------------------------------------------*
int Trailing_Zeros(int n){ // number of zeros for n!
    int ans=0;
    while(n){
        n/=5;
        ans+=n;
    }
    return ans;
}
