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
int sum_all_toN (int n) {return n = n*(n+1)/2;}
int sum_allEven_toN (int n) {return  n = (n/2)*((n/2)+1);}
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
int comp_double(double x, double y) {
        if(fabs(x-y)<=1e-9)return 0;
        return x<y?-1:1;
}
*----------------------------------------------------------------------*
5/7 = 0.714285 =.0 (714285) ------ 1/6 = 0.1666666 = .1 (6)
pair<string ,string> result(int a,int b){
    int result, remainder, index;
    map<int, int> remainderIndex;
    vector<int> decimalDigits;
    index = 0;
    result = a / b;
    remainder = a % b;
    while (!remainderIndex.count(remainder)) {
        remainderIndex[remainder] = index++;
        result = remainder * 10 / b;
        decimalDigits.push_back(result);
        remainder = (remainder * 10) % b;

    }
    int cycleStartIndex = remainderIndex[remainder];
    int nCurDigit = 0;
    string s1="",s2="";
    for (; nCurDigit < cycleStartIndex && nCurDigit < 50; nCurDigit++) {
        s1+= to_string(decimalDigits[nCurDigit]);
    }
    for (; nCurDigit < index && nCurDigit < 50; nCurDigit++) {
        s2+= to_string(decimalDigits[nCurDigit]);
    }
    return {s1,s2};
}
