__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }

string multiply(string s1,string s2){
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int a[600];
    memset(a, 0, sizeof(a));
    for (int i=0; i<s1.length(); i++) {
        for (int j=0; j<s2.length(); j++) {
            a[i + j] += (s1[i]-'0') * (s2[j] - '0');
        }
    }
    for (int i=0; i<600 - 1; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    int i = 600 - 1;
    while (i > 0 && a[i] == 0) i--;
    string s="";
    for (; i>=0; i--) s += to_string(a[i]);
    return s;
}
