// http://www.51nod.com/contest/problemList.html#!contestId=42
// http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1829
// http://blog.csdn.net/zuzhiang/article/details/78561948

#include<iostream>
using namespace std;

const int MAXN = 1000010;
const long long mod = 1e9+7;

long long fac[MAXN],inv[MAXN]; //fac表示阶乘，inv表示阶乘的逆元   

long long pow(long long a, long long b)  
{ //快速幂取模   
    long long r=1,base=a;  
    while(b)  
    {  
        if(b&1) r=r*base%mod;  
        base=base*base%mod;  
        b>>=1;  
    }  
    return r;  
}  

long long C(long long n,long long m)  
{ //根据组合数公式求组合数   
    if(m>n) return 0;  
    if(m==0) return 1;  
    return fac[n]*inv[m]%mod * inv[n-m]%mod; //利用了同余模定理   
}  

void init() {
	//求每个数的阶乘和阶乘的逆元   
    int i;  
    fac[0]=1;  
    for(i=1;i<MAXN;i++) //求阶乘   
        fac[i]=fac[i-1]*i%mod;  
    inv[MAXN-1]=pow(fac[MAXN-1],mod-2); //根据费马定理求最后一个数阶乘的逆元   
    for(i=MAXN-2;i>=0;i--) //根据公式求每个阶乘的逆元   
        inv[i]=inv[i+1]*(i+1)%mod;  
    /* 因为用到快速幂，会超时  
    inv[1]=1; 
    for(i=2;i<MAXN;i++) 
        inv[i]=(inv[i-1]*pow(i,mod-2))%mod;*/     
}

long long stirling(int n, int m) {
    // priciple of inclusion and exclusion
    // s(m, n) = \frac{1}{n!} \sum_{i=0}^n (-1)^i \binom{n}{i} (n-i)^m
	long long ans = 0;
	int e = 1;
	for(int i=0;i<=m;i++)  
    { //结果是很多数之和   
        ans+=C(m,i)*pow(m-i,n)%mod*e;  
        ans%=mod;  
        e*=-1;  
    }  
	return (ans+mod)%mod;
}

long long solve(int n, int m) {
    // TODO:
    return stirling(n, m);
}

int main() {
	init();
    long long n, m;
    cin>>n>>m;
    cout<<solve(n, m)<<endl;
    return 0;
}

// number of surjection:  https://math.stackexchange.com/questions/264799/calculating-the-total-number-of-surjective-functions
// computation of Stirling number: http://math2.uncc.edu/~ghetyei/courses/old/S07.3166/stirling.pdf

// generating function: F(x) = (e^x - 1)^m = \sum_{k=0}^m C_m^k e^{kx} (-1)^{m-k}
// then find the coefficients of x^n / n!, which is exactly f(n, m)

// Inclusion–exclusion principle: 
// \sum_{i=0}^m (-1)^i \binom{m}{i} (m-i)^n.

// note here we use exponential generating function:
// 1+x+\dots+x^k+\dots = \frac{1}{1-x}, 
// while 1+x+\dots+ x^k / k! + \dots = e^x.

// notice here: \sum_{i=0}^m (-1)^i \binom{m}{i} (m-i)^n is the same as 
// \sum_{i=0}^m (-1)^{m-i} \binom{m}{i} i^n
