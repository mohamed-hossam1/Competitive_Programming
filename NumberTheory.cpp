vector<int> Divisors(int n){//sqrt(n)
    vector<int> v;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i==0){
            v.push_back(i);
            if(i*i!=n)
            v.push_back(n/i);
        }
    }
    return v;
}

int gcd(int a,int b){ //log(n)
    if(b>a) swap(a,b);
    if(b==0) return a;
    return gcd(a%b,b);
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}

bool isprime(int n){
    if(n==1)return 0;
    if(n!=2&&n%2==0) return 0;
    for (int i = 3; i*i <= n; i+=2)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
vector<int> primeFactors(int n){//sqrt(n)
    vector<int> v;
    for (int i = 2; i*i <= n; i++)
    {
        while (n%i==0){
            v.push_back(i);
            n/=i;
        }
    }
    if(n>1)v.push_back(n);
    return v;
}
int power(int a,int b){
    if(b==0)return 1;
    if(b==1)return a;
    
    int ret=1;
    if(b&1) ret =  a;
    int x = power(a,b/2);
    return ret*x*x;
}
int powermod(int a,int b,int mod){
    if(b==0)return 1;
    if(b==1)return a;
    
    int ret=1;
    if(b&1) ret =  a%mod;
    int x = powermod(a,b/2,mod);
    ret = ret*x*x;
    return ret%mod;
}
vector<bool> sieve(int n){
    vector<bool> prime(n,1);
    prime[0]=prime[1]=0;
    for (int i = 2; i*i < n; i++)
    {
        if(prime[i]){
            for (int j = i*i; j < n; j+=i)
            {
                prime[j]=0;
            }
            
        }
    }
    return prime;
}
vector<bool> linearSieve(int N)
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

//  mod 
add (x % m + y % m) % m;
mul (x % m * y % m) % m ;
sub (((x % m - y % m) % m) + m) % m;
div y = powermod(b,mod-2,mod);
     (x % m * y % m) % m ;
a ^ (mod - 1) % mod = 1


