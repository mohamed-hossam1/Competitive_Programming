const int MOD = 1e9 + 7;
int factorial(int n, int mod = MOD) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}
*----------------------------------------------------------------------*
int power(int a,int b, int mod = MOD) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}
*----------------------------------------------------------------------*
int modInverse(int a, int mod = MOD) {return power(a, mod - 2, mod);}
*----------------------------------------------------------------------*
int nCr(int n, int r, int mod = MOD) {
    return (factorial(n, mod)* modInverse(factorial(r, mod), mod) % mod * modInverse(factorial(n - r, mod), mod) % mod) % mod;
}
*----------------------------------------------------------------------*
int nPr(int n, int r, int mod = MOD) {
    return (factorial(n, mod) * modInverse(factorial(n - r, mod), mod) % mod) % mod;
}
*----------------------------------------------------------------------*
int factorial(int n) {
   if (n == 0 || n == 1){
       return 1;
   }
   return n * factorial(n - 1);
}
*----------------------------------------------------------------------*
int ncr(int n,int r){
  return factorial(n) / (factorial(r) * factorial(n-r));
}
*----------------------------------------------------------------------*
int npr(int n,int r){
  return factorial(n) / factorial(n-r);
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


