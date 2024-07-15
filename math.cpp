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


sum all of numbers to n = n*(n+1)/2
sum all of even numders to n = (n/2)*((n/2)+1)/2

the number has odd distinct divisors if sqrt(number) == (int) sqrt(number)
16 
sqrt(16)=4
1 2 4 8 16


the number has three distinct divisors if sqrt(number) == (int) sqrt(number)
and sqrt(number) = prime number 
49 
sqrt(49) 7 
so divisors of 49 = 1 7 49





long long int_sqrt (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}

