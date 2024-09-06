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
int sum_all_toN (int n) {return n = n*(n+1)/2;}
int sum_allEven_toN (int n) {return  n = (n/2)*((n/2)+1);}
double gold = (1 + sqrt(5)) / 2;
int Fibonacci(int an){return round((pow(gold,6)-pow(1-gold,6))/sqrt(5));}  }
*----------------------------------------------------------------------*
int comp_double(double x, double y) {
        if(fabs(x-y)<=1e-9)return 0;
        return x<y?-1:1;
}
*----------------------------------------------------------------------*
vector<int> v = {2, 3, 5, 7};
int n = 100;
int inc_exe(int idx = 0, int d = 1, int sign = -1) {
    if (idx == v.size()) 
    if(d==1) return 0;
    else return sign * n / d;

    else return inc_exe(idx + 1, d,sign) + inc_exe(idx + 1, d * v[idx], sign * - 1);
}
*----------------------------------------------------------------------*
vector<vector<int>> multiplyMatrices(vector<vector<int>>& mat1,vector<vector<int>>& mat2) {
    int rows = mat1.size();
    int cols = mat2[0].size();
    int common = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}
*----------------------------------------------------------------------*
double determinant2x2(const vector<vector<double>>& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}
*----------------------------------------------------------------------*
double determinant3x3(const vector<vector<double>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}
*----------------------------------------------------------------------*
pair<double, double> solveQuadratic(double a, double b, double c) { //ax^2 + bx + c = 0
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return {-1, -1}; // No real solutions
    }
    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);
    return {root1, root2};
}
*----------------------------------------------------------------------*
double Nth_Root_X(double x, int n) { 
    double guess = x / n;
    double epsilon = 1e-7;
    while (abs(pow(guess, n) - x) > epsilon) {
        guess = ((n - 1) * guess + x / pow(guess, n - 1)) / n;
    }
    return guess;
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
