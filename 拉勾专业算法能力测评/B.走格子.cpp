#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

const int maxn = 5e4;
long long A[maxn+5];
int n;

long long solve() {
    long long temp = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        temp += A[i];
        if (temp < ans) {
            ans = temp;
        }
    }
    return -ans;
}

int main() {
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>A[i];

    long long ans = solve();
    cout<<ans<<endl;
    return 0;
}