2D Prefix Sum
void solve() {
    int x, y;
    cin >> x >> y;    
    vector<vector<int>> arr(x, vector<int>(y));

    for (int i = 0; i < x; ++i) 
        for (int j = 0; j < y; ++j) 
            cin >> arr[i][j];
    
    vector<vector<int>> twopre(x + 1, vector<int>(y + 1, 0));    
    for (int i = 1; i <= x; ++i)
        for (int j = 1; j <= y; ++j) 
            twopre[i][j] = arr[i-1][j-1] + twopre[i-1][j] + twopre[i][j-1] - twopre[i-1][j-1];//if arr is zero bias

    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << twopre[r2][c2] - twopre[r1-1][c2] - twopre[r2][c1-1] + twopre[r1-1][c1-1] << endl;
    }
}
*----------------------------------------------------------------------*
3D Prefix Sum
void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    
    vector<vector<vector<int>>> arr(x, vector<vector<int>>(y, vector<int>(z)));
    
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cin >> arr[i][j][k];
            }
        }
    }
    vector<vector<vector<int>>> threepre(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, 0)));    
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            for (int k = 1; k <= z; ++k) {
                threepre[i][j][k] = arr[i-1][j-1][k-1]
                                  + threepre[i-1][j][k]
                                  + threepre[i][j-1][k]
                                  + threepre[i][j][k-1]
                                  - threepre[i-1][j-1][k]
                                  - threepre[i-1][j][k-1]
                                  - threepre[i][j-1][k-1]
                                  + threepre[i-1][j-1][k-1];
            }
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        cout << threepre[x2][y2][z2]
             - threepre[x1-1][y2][z2]
             - threepre[x2][y1-1][z2]
             - threepre[x2][y2][z1-1]
             + threepre[x1-1][y1-1][z2]
             + threepre[x1-1][y2][z1-1]
             + threepre[x2][y1-1][z1-1]
             - threepre[x1-1][y1-1][z1-1] << endl;
    }
}
*----------------------------------------------------------------------*
void printSubsequence(string input, string output="")//O(n* 2^n)
{
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}
*----------------------------------------------------------------------*
struct compare {
    bool operator() (const string& a, const string& b) const{
        return a.size() < b.size();
    }
};
set<string, compare>
*----------------------------------------------------------------------*
int maxSubsetXOR(vector<int> v)
{
    int index = 0;
    for (int i = 32-1; i >= 0; i--)
    {
        int maxInd = index;
        int maxEle = INT_MIN;
        for (int j = index; j < v.size(); j++)
        {
            if ( (v[j] & (1 << i)) != 0 && v[j] > maxEle ) maxEle = v[j], maxInd = j;
        }

        if (maxEle == INT_MIN)
        continue;
        swap(v[index], v[maxInd]);
        maxInd = index;
        for (int j=0; j<v.size(); j++) if (j != maxInd &&(v[j] & (1 << i)) != 0)v[j] = v[j] ^ v[maxInd];

        index++;
    }
    int res = 0;
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    return res;
}
*----------------------------------------------------------------------*
int xorsubset(vector<int> v) 
{ 
    int bits = 0; 
    for (int i=0; i < v.size(); ++i) bits |= v[i]; 
    int ans = bits * pow(2, v.size()-1); 
    return ans; 
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

auto sum = [&]() -> int{
    
        return ;
};
