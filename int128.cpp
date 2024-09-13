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
Dr Mostafa Saad code https://ideone.com/upppJ1
7oSkaaa code
struct BigInt {

    const int BASE = 1000000000;
    vector < int > v;
    
    BigInt() {}

    BigInt(const long long &val) {
        *this = val;
    }
    
    BigInt(const string &val) {
        *this = val;
    
    }
    
    int size() const { return v.size(); }
    
    bool zero() const { return v.empty(); }
    
    BigInt& operator = (long long val) {
        v.clear();
        while (val) {
            v.push_back(val % BASE);
            val /= BASE;
        }
        return *this;
    }

    BigInt& operator = (const BigInt &a) {
        v = a.v;
        return *this;
    }

    BigInt& operator = (const vector < int > &a) {
        v = a;
        return *this;
    }

    BigInt& operator = (const string &s) {
        *this = 0;
        for (const char &ch : s)
            *this = *this * 10 + (ch - '0');
        return *this;
    }
    
    bool operator < (const BigInt &a) const {
        if (a.size() != size())
            return size() < a.size();
        for (int i = size() - 1; i >= 0; i--)
            if (v[i] != a.v[i])
                return v[i] < a.v[i];
        return false;
    }

    bool operator > (const BigInt &a) const {
        return a < *this;
    }

    bool operator == (const BigInt &a) const {
        return (!(*this < a) && !(a < *this));
    }

    bool operator <= (const BigInt &a) const {
        return ((*this < a) || !(a < *this));
    }
    
    ll val(){
        ll ans = 0;
        for (int i = 0; i < size(); i++)
            ans = ans * 10 + v[i];
        return ans;
    }

    BigInt operator + (const BigInt &a) const {
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
    }
    
    BigInt& operator += (const BigInt &a) {
        *this = *this + a;
        return *this;
    }
    
    BigInt operator * (const BigInt &a) const {
        BigInt res;
        if (this -> zero() || a.zero())
            return res;
        res.v.resize(size() + a.size());
        for (int i = 0; i < size(); i++) {
            if (v[i] == 0)
                continue;
            long long carry = 0;
            for (int j = 0; carry || j < a.size(); j++) {
                carry += 1LL * v[i] * (j < a.size() ? a.v[j] : 0);
                while (i + j >= res.size())
                    res.v.push_back(0);
                carry += res.v[i + j];
                res.v[i + j] = carry % BASE;
                carry /= BASE;
            }
        }
        while (!res.v.empty() && res.v.back() == 0)
            res.v.pop_back();
        return res;
    }

    BigInt& operator *= (const BigInt &a) {
        *this = *this * a;
        return *this;
    }

    BigInt& operator -= (const BigInt &b){
        if(*this < b)
            throw("UNDERFLOW");
        int n = this -> size(), m = b.size();
        int i, t = 0, s;
        for (i = 0; i < n;i++){
            if(i < m)
                s = this -> v[i] - b.v[i]+ t;
            else
                s = this -> v[i] + t;
            if(s < 0)
                s += 10,
                t = -1;
            else
                t = 0;
            this -> v[i] = s;
        }
        while(n > 1 && this -> v[n - 1] == 0)
            this -> v.pop_back(),
            n--;
        return *this;
    }

    BigInt operator - (const BigInt&b){
        BigInt a = *this;
        a -= b;
        return a;
    }

    BigInt& operator /=(const ll a) {
        ll carry = 0;
        for (int i = (int) v.size() - 1; i >= 0; i--) {
            ll cur = v[i] + carry * BASE;
            v[i] = cur / a;
            carry = cur % a;
        }
        while (!v.empty() && v.back() == 0)
            v.pop_back();
        return *this;
    }
    
    BigInt operator / (const ll a) {
        ll carry = 0;
        vector < int > res = this -> v;
        for (int i = (int) res.size() - 1; i >= 0; i--) {
            ll cur = res[i] + carry * BASE;
            res[i] = cur / a;
            carry = cur % a;
        }
        BigInt ans;
        ans = res;
        return ans;
    }
    
    BigInt operator % (const ll a){
        ll res = 0;
        for (int i = (int) v.size() - 1; i >= 0; i--)
            res = (res * 10 + v[i]) % a;
        BigInt ans = res;
        return ans;
    }

    BigInt& operator %= (const ll a) {
        *this = *this % a;
        return *this;
    }

    friend ostream& operator<<(ostream &out, const BigInt &a) {
        out << (a.zero() ? 0 : a.v.back());
        for (int i = (int) a.v.size() - 2; i >= 0; i--)
            out << setfill('0') << setw(9) << a.v[i];
        return out;
    }

    friend istream& operator>>(istream &in, BigInt &a) {
        string s;
        in >> s;
        a = s;
        return in;
    }

};
