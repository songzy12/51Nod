#include<iostream>
using namespace std;

const int p = 1e9+7;

long long solve(int n, int m) {
    // TODO:
    return 0;
}

int main() {
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