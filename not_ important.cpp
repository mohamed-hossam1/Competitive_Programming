
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


unordered_set<string> st;
void allsubsequence(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);
            
            for (int k = 1; k < sub_str.length() - 1; k++)
            {
                string sb = sub_str;
                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}
