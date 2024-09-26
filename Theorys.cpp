*----------------------------------------------------------------------*
N % 3 == 0 if (sum all digits) % 3 == 0 ,N % 4 == 0 if (last two digits) % 4 == 0
N % 5 == 0 if last digit == (5||0) ,N % 6 == 0 if (sum all digits) % 3 == 0 && N is even
N % 8 == 0 if (last three digits) % 8 == 0 , N % 9 == 0 if (sum all digits) % 9 == 0
N % 11 == 0 if(Add,sub digits in alternating) % 11 == 0
*----------------------------------------------------------------------*
the number has odd divisors if sqrt(number) == (int) sqrt(number)
16 -> 1 2 4 8 16
*----------------------------------------------------------------------*
the number has three divisors if sqrt(number) == (int) sqrt(number) && sqrt(number) = prime number 
49 -> 1 7 49
*----------------------------------------------------------------------*
the range for gcd(a,b) 1->min(b,a)
*----------------------------------------------------------------------*
gcd(a,b)=gcd(b,a%b)
*----------------------------------------------------------------------*
gcd(1,n) = 1  lmc(1,n) = n    
*----------------------------------------------------------------------*
gcd(a,b) == min(b,a) when a = k*b         and == 1 if a = k*b (+|-) 1
gcd(4,4) = gcd(4,8) = gcd(4,12) = 4       gcd(4,3) = gcd(4,5) = gcd(4,11) = 1 
*----------------------------------------------------------------------*
a ^ (mod - 1) % mod = 1         when mod is prime or mod and a are coprime
*----------------------------------------------------------------------*
a,b are coprime if gcd(a,b)=1 
*----------------------------------------------------------------------*
(p-1)! ≡ p-1 (mod p) if p prime             p^2 − 1 = 24*n   p = prime > 3             2^n − 1 must be prime  
*----------------------------------------------------------------------*
Perfect Numbers: the sum of its distinct factors = number
6 ---> 1,2,3 && 1+2+3=6
Theory 2^(n-1) * (2^n - 1) must be Perfect Number if n = prime && (2^n - 1) = prime 
*----------------------------------------------------------------------*


