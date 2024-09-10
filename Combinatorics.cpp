int fact[N];
int fastpow(int a,int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

void factorial() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = i*fact[i-1] % MOD;
}

int modInverse(int a) {return fastpow(a,MOD-2);}

int nCr(int n, int r) {
    return (fact[n] * modInverse(fact[r]) % MOD * modInverse(fact[n - r]) % MOD) % MOD;
}

int nPr(int n, int r) {
    return (fact[n] * modInverse(fact[n - r])% mod) % mod;
}
*----------------------------------------------------------------------* 
int npr(int n,int r){
    int ans =1;
    for(int i = n-r+1; i<=n; i++) ans*=i;
    return ans;
}

int ncr(int n, int r)
{
    int ans = 1, rfact = 2;
    for (int i = n - r + 1; i <= n; i++)
    {
        ans *= i;
        if (ans % rfact == 0 && rfact <= r) ans /= rfact++;
    }
    return ans;
}
*----------------------------------------------------------------------*
int pascal[10000][10000];
void pascalncr()
{
    for (int i = 0; i < 10000; i++)
        pascal[i][0] = pascal[i][i]=1;
    for (int i = 1; i < 10000; i++)
        for (int j = 1; j < i; j++)
            pascal[i][j] = (pascal[i - 1][j] + pascal[i - 1][j - 1])%mod;
}
*----------------------------------------------------------------------*
int arr[4] = {2, 3, 5, 7};//prime
int n = 100;
int Inclusion_Exclusion(int idx = 0, int d = 1, int sign = -1) {
    if (idx == 4) {
        if (d == 1)
            return 0; 
        return sign * n / d;
    }
    return Inclusion_Exclusion(idx + 1, d, sign) + Inclusion_Exclusion(idx + 1, d * arr[idx], sign * -1);
}
*----------------------------------------------------------------------*
long long starsAndBars(int n, int k, int mod = MOD) {
    return nCr(n + k - 1, k - 1, mod);
}


