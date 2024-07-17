*----------------------------------------------------------------------*
         متتابعه حسابيه
      a1 a1+d a1+2d ------ an   
int sum (int ai,int an,int n) {
  return ((ai + an) * n) / 2;
}
int find_an(int a1,int n,int d){
  return a1 + (n - 1) * d;
}
int find_d(int a1,int a2){
  return a2-a1;
}
*----------------------------------------------------------------------*
         متتابعه هندسيه 
      a1 a1*r a1*r*r ------ an   
int sum (int ai,int n) {
  return a1*(1-pow(r,n))/(1-r);
}
int find_an(int a1,int n,int d){
  return a1 * pow(r,(n-1));
}
int find_r(int a1,int a2){
  return a2/a1;
}
*----------------------------------------------------------------------*
int sum_all_toN (int n) return n = n*(n+1)/2;
sum_allEven_toN (int n) return  n = (n/2)*((n/2)+1)/2
*----------------------------------------------------------------------*
int comp_double(double x, double y) {
        if(fabs(x-y)<=1e-9)return 0;
        return x<y?-1:1;
}
*----------------------------------------------------------------------*
k-th_is_not_divisible_by_n(int n,int k) return k + (k - 1) / (n - 1); // n = 3 k = 7 --numbers not divisible by 3 1,2,4,5,7,8,*10*,11,13… 

long long int_sqrt (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}
*----------------------------------------------------------------------*

