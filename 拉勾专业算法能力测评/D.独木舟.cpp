#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

const int maxn = 1e5;
long long A[maxn+5];

int main() {
    int n;
    long long m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>A[i];
    }
    sort(A, A+n);
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j) {
        while (i < j && A[i] + A[j] > m) {
            j--;
            ans++;
        }
        if (i < j) {
            ans++;
            i ++;
            j --;
        }
    }
    if (i == j)
        ans++;
    cout<<ans<<endl;
    return 0;
}
