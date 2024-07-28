int arr[4] = {2, 3, 5, 7};
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
