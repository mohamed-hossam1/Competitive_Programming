 and       or      xor 
1 1 1    0 1 1    0 1 1
1 0 0    0 0 0    0 0 0
0 1 0    1 1 1    1 1 0
0 0 0    1 0 1    1 0 1 
bool Knowbit(ll n,int i){ return (n >> i) & 1; }
ll Setbit(ll n,int i){return n | (1LL << i); }
ll Resetbit(ll n,int i){return n & ( ~ (1LL << i)); }
ll flip(ll n,int i){return n ^ (1LL << i); }
int lowbit(int n){return (n&~(n-1));}
__lg(x) //index of highbit----->zero base
__builtin_popcount(n); //count the number of one’s
__builtin_ctz(x) //zeros from last to first occurrence of one
__builtin_clz(x) //number of zeros before the first occurrence of one
bitset<32> a;
a.to_ullong() //to int
*----------------------------------------------------------------------*
vector<vector<int>> get_all_subsets(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> subsets;
    
    for (int i = 0; i < (1LL << n); i++) { 
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1LL << j)) { 
                subset.push_back(arr[j]);
            }
        }
        subsets.push_back(subset);
    }
    
    return subsets;
}
*----------------------------------------------------------------------*
 string Binarytogray(string s){
    string ans="";
    ans+=s[0];
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]) ans+='0';
        else ans+='1';

    }
    return ans;
}
*----------------------------------------------------------------------*
string graytoBinary(string s)
{
    string ans = "";
    ans += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') ans += ans[i - 1];
        else 
        {
            if (ans[i - 1] == '0') ans += '1';
            else ans += '0';
        }
    }
    return ans;
}
*----------------------------------------------------------------------*
int BinarytoDecemal(string s){
    int ans=0;
    int bin =1;
    for(int i=s.size()-1;i>=0;i--){
        ans +=bin*(s[i]-'0');
        bin *=2; 
    }
    return ans;
}
*----------------------------------------------------------------------*
int XORtoN(int n)
{
    int mod = n % 4;
    if (mod == 0) return n;
    else if (mod == 1) return 1;
    else if (mod == 2) return n + 1;
    return 0;

}

Theorys
a^b = c
c^a = b
a+b = (a^b)+2(a&b)
a^b^a=b
    

