#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool Knowbit(ll n,int i)
{
    return (n>>i)&1;
}
ll Setbit(ll n,int i)
{
    return n|(1<<i);
}
ll Resetbit(ll n,int i)
{
    return n&(~(1<<i));
}
ll flip(ll n,int i)
{
    return n^(1<<i);
}
bool isPowerOfTwo(int n)
{
    if(n==0)return 0;
    return !(n&(n-1));
}
int countFoOnes(int n){
    return __builtin_popcount(n);
}
 and       or      xor 
1 1 1    0 1 1    0 1 1
1 0 0    0 0 0    0 0 0
0 1 0    1 1 1    1 1 0
0 0 0    1 0 1    1 0 1 

a^b = c
c^a = b
bitset<32> a;
a.count(); // count of ones
