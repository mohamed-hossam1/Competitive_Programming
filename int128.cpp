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
//           *BigInt*
struct BigInt {
    const int BASE = 1000000000;
    vector<int> v;
    bool sign; 

    BigInt() : sign(true) {}

    BigInt(const long long &val) {
        *this = val;
    }

    BigInt(const string &val) {
        *this = val;
    }

    int size() const { return v.size(); }

    bool zero() const { return v.empty(); }

    void normalize() {
        while (!v.empty() && v.back() == 0)
            v.pop_back();
        if (v.empty())
            sign = true; 
    }

    BigInt& operator = (long long val) {
        v.clear();
        sign = (val >= 0);
        if (val < 0) val = -val;
        while (val) {
            v.push_back(val % BASE);
            val /= BASE;
        }
        normalize();
        return *this;
    }

    BigInt& operator = (const BigInt &a) {
        v = a.v;
        sign = a.sign;
        return *this;
    }

    BigInt& operator = (const string &s) {
        *this = 0;
        sign = (s[0] != '-');
        for (int i = (s[0] == '-' ? 1 : 0); i < s.size(); ++i)
            *this = *this * 10 + (s[i] - '0');
        return *this;
    }

    bool operator < (const BigInt &a) const {
        if (sign != a.sign) return !sign;
        if (size() != a.size()) return sign ? (size() < a.size()) : (size() > a.size());
        for (int i = size() - 1; i >= 0; i--)
            if (v[i] != a.v[i])
                return sign ? (v[i] < a.v[i]) : (v[i] > a.v[i]);
        return false;
    }

    bool operator == (const BigInt &a) const {
        return sign == a.sign && v == a.v;
    }

    BigInt operator + (const BigInt &a) const {
        if (sign == a.sign) {
            BigInt res = *this;
            int idx = 0, carry = 0;
            while (idx < a.size() || carry) {
                if (idx < a.size())
                    carry += a.v[idx];
                if (idx == res.size())
                    res.v.push_back(0);
                res.v[idx] += carry;
                carry = res.v[idx] / BASE;
                res.v[idx] %= BASE;
                idx++;
            }
            return res;
        } else {
            return *this - (-a);
        }
    }

    BigInt operator - (const BigInt &a) const {
        if (sign != a.sign) {
            return *this + (-a);
        } else if (*this < a) {
            return -(a - *this);
        } else {
            BigInt res = *this;
            int idx = 0, borrow = 0;
            while (idx < a.size() || borrow) {
                if (idx < a.size())
                    res.v[idx] -= a.v[idx] + borrow;
                else
                    res.v[idx] -= borrow;
                if (res.v[idx] < 0) {
                    res.v[idx] += BASE;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                idx++;
            }
            res.normalize();
            return res;
        }
    }

    BigInt operator * (const BigInt &a) const {
        BigInt res;
        res.v.resize(size() + a.size());
        res.sign = (sign == a.sign);
        for (int i = 0; i < size(); i++) {
            if (v[i] == 0) continue;
            long long carry = 0;
            for (int j = 0; carry || j < a.size(); j++) {
                carry += 1LL * v[i] * (j < a.size() ? a.v[j] : 0);
                carry += res.v[i + j];
                res.v[i + j] = carry % BASE;
                carry /= BASE;
            }
        }
        res.normalize();
        return res;
    }

    BigInt operator -() const {
        BigInt res = *this;
        if (!zero()) res.sign = !sign;
        return res;
    }

    BigInt& operator += (const BigInt &a) {
        *this = *this + a;
        return *this;
    }

    BigInt& operator -= (const BigInt &a) {
        *this = *this - a;
        return *this;
    }

    // القسمة
    BigInt& operator /= (const BigInt &a) {
        *this = *this / a;
        return *this;
    }

    BigInt operator / (const BigInt &a) const {
        if (a.zero()) throw runtime_error("Division by zero");

        BigInt res, cur;
        res.sign = (sign == a.sign);
        cur.sign = true;

        for (int i = (int)v.size() - 1; i >= 0; i--) {
            cur.v.insert(cur.v.begin(), v[i]);
            cur.normalize();
            int x = 0, l = 0, r = BASE;
            while (l <= r) {
                int m = (l + r) / 2;
                BigInt t = a * m;
                if (t < cur||t == cur) {
                    x = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            res.v.push_back(x);
            cur = cur - a * x;
        }

        reverse(res.v.begin(), res.v.end());
        res.normalize();
        return res;
    }

    // باقي القسمة
    BigInt operator % (const BigInt &a) const {
        return *this - (*this / a) * a;
    }

    BigInt& operator %= (const BigInt &a) {
        *this = *this % a;
        return *this;
    }

    friend ostream& operator<<(ostream &out, const BigInt &a) {
        if (!a.sign) out << '-';
        if (a.zero()) out << 0;
        else {
            out << (a.v.empty() ? 0 : a.v.back());
            for (int i = (int) a.v.size() - 2; i >= 0; i--)
                out << setfill('0') << setw(9) << a.v[i];
        }
        return out;
    }

    friend istream& operator>>(istream &in, BigInt &a) {
        string s;
        in >> s;
        a = s;
        return in;
    }
};
