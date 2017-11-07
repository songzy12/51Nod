#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int compute(int t) {
    int ans = 0;
    while (t) {
        if (t % 10 == 1)
            ans += 1;
        t /= 10;
    }
    return ans;
}

long long solve_(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += compute(i);
    return ans;
}

vector<pair<int, int> > get_digits(int n) {
    vector<pair<int, int> > digits;
    int cur = 0;
    int pow = 1;
    while (n) {
        digits.push_back(make_pair(n % 10, cur));
        cur += (n % 10) * pow;
        pow *= 10;
        n /= 10;
    }
    return digits;
}

const int max_len = 10;
long long dp[max_len + 1];
long long pow10[max_len + 1];

void init() {
    pow10[0] = 1;
    for (int i = 1; i <= max_len; ++i) {
        pow10[i] = 10 * pow10[i-1];
    }

    dp[0] = 0;
    for (int i = 1; i <= max_len; ++i) {
        dp[i] = 10 * dp[i-1] + pow10[i-1];
    }
}

long long solve(int n) {
    long long ans = 0;
    vector<pair<int, int> > digits = get_digits(n);
    init();
    for (int i = digits.size() - 1; i >= 0; --i) {
        int digit = digits[i].first;
        int res = digits[i].second;
        //printf("%d %d %d %lld %lld\n", i, digit, res, pow10[i], dp[i]);
        for (int j = 0; j < digit; ++j) {
            if (j == 1)
                ans += pow10[i];
            ans += dp[i];            
        }
        if (digit == 1)
            ans += res + 1;
    }
    return ans;
}

void check() {
    for (int i = 1; i < 10000; ++i) {
        if (solve(i) != solve_(i)) {
            cout<<i<<" "<<solve(i)<<" "<<solve_(i)<<endl;
            throw;
        }
    }
    cout<<"PASSED"<<endl;
}

int main() {
    int n;
    cin>>n;
    long long ans = solve(n);
    cout<<ans<<endl;
    return 0;
}