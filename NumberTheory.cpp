*----------------------------------------------------------------------*
k-th_is_not_divisible_by_n(int n,int k) return k + (k - 1) / (n - 1);   // n = 3 k = 7 --numbers not divisible by 3 1,2,4,5,7,8,*10*,11,13… 
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
    vector<ll>divsors(1e6+10,0);
    for (int i = 1; i <= (int)1e6; i++) 
	for (int k = i; k <= (int)1e6; k += i) divsors[k]++;
    return divsors;
}
*----------------------------------------------------------------------*
vector<int> primeFactors(int n){//sqrt(n)
    vector<int> v;
    for (int i = 2; i*i <= n; i++)
        while (n%i==0){ v.push_back(i); n/=i; }
    if(n>1)v.push_back(n);
    return v;
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
int power(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    int ret=1;
    if(b&1) ret =  a;
    int x = power(a,b/2);
    return ret*x*x;
}
*----------------------------------------------------------------------*
int powermod(int a,int b,int mod){
    if(b==0)return 1;
    if(b==1)return a;
    int ret=1;
    if(b&1) ret =  a%mod;
    int x = powermod(a,b/2,mod);
    ret = ret*x*x;
    return ret%mod;
}
*----------------------------------------------------------------------*
int phi(int n) { //sum of coprime numbers from 1 to n //sqrt(n)
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
pair<int,int> euclid(int a,int b,int& x,int& y){  //a*x+b*y=gcd(a,b) return x,y     .........       (a*b)%m=1 and b==x if euclid(a,m);
    if(b==0){
        x=1;
        y=0;
        return {x,y};
    }
    int x1,y1;
    euclid(b,a%b,x1,y1);
    x=y1 , y=x1-y1*(a/b);
    return {x,y};
}
*----------------------------------------------------------------------*
int add(int x,int y,int mid) {return(x % mod + y % mod) % mod;}
int mul(int x,int y,int mid) {return(x % mod * y % mod) % mod;}
int sub(int x,int y,int mid) {return(((x % mod - y % mod) % mod) + mod) % mod;}
int div(int x,int y,int mid) {return(x % mod * powermod(y,mod-2,mod) % mod) % mod;}
int mod_negative(int x,int m) {return(x%m)+m%m;}
*----------------------------------------------------------------------*


